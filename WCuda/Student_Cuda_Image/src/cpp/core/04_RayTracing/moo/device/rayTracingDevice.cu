#include "Indice2D.h"
#include "cudaTools.h"
#include "Device.h"

#include "IndiceTools_GPU.h"

#include "RayTracingMath.h"
#include "length_cm.h"

using namespace gpu;

// Attention : 	Choix du nom est impotant!
//		VagueDevice.cu et non Vague.cu
// 		Dans ce dernier cas, probl�me de linkage, car le nom du .cu est le meme que le nom d'un .cpp (host)
//		On a donc ajouter Device (ou n'importequoi) pour que les noms soient diff�rents!

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

// Déclaration Constante globale
__constant__ Sphere TAB_CM[NB_SPHERE];
/**
 * call once by the host
 */
__host__ void uploadToCM(Sphere* tabValue)
    {
    size_t size = NB_SPHERE * sizeof(Sphere);
    int offset = 0;
    HANDLE_ERROR(cudaMemcpyToSymbol(TAB_CM, tabValue, size, offset, cudaMemcpyHostToDevice));
    }

__device__ void work(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrDevTabSphere, int nbSphere)
    {
    RayTracingMath rayTracingMath = RayTracingMath(t,nbSphere, ptrDevTabSphere);

        const int TID = Indice2D::tid();
        const int NB_THREAD = Indice2D::nbThread();
        const int WH = w * h;


        int i;	// in [0,h[
        int j; 	// in [0,w[

        int s = TID; // in [0,...
        while (s < WH)
    	{
    	IndiceTools::toIJ(s, w, &i, &j); // s[0,W*H[ --> i[0,H[ j[0,W[

    	rayTracingMath.colorIJ(&ptrDevPixels[s], i, j); // update ptrTabPixels[s]

    	s += NB_THREAD;
    	}
    }

__global__ void rayTracing(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrDevTabSphere, int nbSphere)
    {
    //global memory
    work(ptrDevPixels,w,h,t,ptrDevTabSphere,nbSphere);
    }

__global__ void rayTracingToCM(uchar4* ptrDevPixels, uint w, uint h, float t, int nbSphere)
    {
    //constant memory
    work(ptrDevPixels,w,h,t,TAB_CM,nbSphere);
    }

__device__ void copyGMtoSM(Sphere* tabGM, Sphere* tabSM, int n)
    {
    const int NB_THREAD_LOCAL = Indice2D::nbThreadLocal();
    const int TID_LOCAL = Indice2D::tidBlock();
    int s = TID_LOCAL;
    while(s<n)
	{
	tabSM[s]=tabGM[s];
	s+=NB_THREAD_LOCAL;
	}
    }

__global__ void rayTracingToSM(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrDevTabSphere, int nbSphere)
    {
    //shared mem
    __shared__ extern Sphere tabSM[];
    copyGMtoSM(ptrDevTabSphere,tabSM,nbSphere);
    __syncthreads();
    work(ptrDevPixels,w,h,t,tabSM,nbSphere);
    }


/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/



/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

