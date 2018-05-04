#include "Indice2D.h"
#include "Indice1D.h"
#include "cudaTools.h"
#include "reductionADD.h"

#include <stdio.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void slicing(float* ptrTabGM,int n);
__global__ void slicingAdvanced(float* ptrTabGM,int n);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static __device__ void reductionIntraThread(float* tabSM, int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * output : void required !!
 */
__global__ void slicing(float* ptrTabGM,int n)
    {
    const int NB_THREAD = Indice2D::nbThread();
    const int TID = Indice2D::tid();
    const float DX = 1.0f / (float) n;

    //pattern entrelacement
    int s = TID;
    float xs;
    float sommeThread = 0;

    while (s < n)
	{
	xs = s * DX;
	sommeThread += 1 / (1 + xs * xs);
	s += NB_THREAD;
	}

    ptrTabGM[TID] = 4*sommeThread;
    }


__global__ void slicingAdvanced(float* ptrTabGM,int n)
    {

    extern __shared__ float tabSM[];
    reductionIntraThread(tabSM,n);
    __syncthreads();
    reductionADD<float>(tabSM, ptrTabGM);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/
__device__ void reductionIntraThread(float* tabSM, int n)
    {
	const int NB_THREAD = Indice1D::nbThread();
        const int TID = Indice1D::tid();
        const int TID_LOCAL = Indice1D::tidLocal();
        const float DX = 1.0f / (float) n;

        //pattern entrelacement
        int s = TID;
        float xs;
        float sommeLocale = 0;

        while (s < n)
    	{
    	xs = s * DX;
    	sommeLocale += 1 / (1 + xs * xs);
    	s += NB_THREAD;
    	}

        tabSM[TID_LOCAL] = 4*sommeLocale*DX;
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

