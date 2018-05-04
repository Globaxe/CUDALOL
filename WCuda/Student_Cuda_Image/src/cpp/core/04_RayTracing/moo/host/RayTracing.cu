#include "RayTracing.h"

#include <iostream>
#include <assert.h>

#include "Device.h"
#include <assert.h>
#include "length_cm.h"


using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void rayTracing(uchar4* ptrDevPixels,uint w, uint h,float t, Sphere* ptrDevTabSphere, int nbSphere);
extern __global__ void rayTracingToCM(uchar4* ptrDevPixels, uint w, uint h, float t, int nbSphere);
extern void uploadToCM(Sphere* tabValue);


/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/



/*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

RayTracing::RayTracing(const Grid& grid, uint w, uint h, int nbSphere, float dt) :
	Animable_I<uchar4>(grid, w, h, "RayTracing_Cuda_RGBA_uchar4")
    {
    SphereCreator sphereCreator(nbSphere,w,h);
    Sphere* ptrTabSphere=sphereCreator.getTabSphere();
    this->sizeOctet = nbSphere*sizeof(Sphere);
    this->nbSphere = nbSphere;

    // global memory et shared mem
	{

	// MM (malloc Device)
	    {
	    Device::malloc(&ptrDevTabSphere, sizeOctet);
	    }

	// MM (copy Host->Device)
	    {
	    Device::memcpyHToD(ptrDevTabSphere, ptrTabSphere, sizeOctet);
	    }
	}

    // Inputs
    this->dt = dt;

    // Tools
    this->t = 0; // protected dans Animable


    //constant memory
    //uploadToCM(ptrTabSphere);
    }

RayTracing::~RayTracing()
    {
    Device::free(ptrDevTabSphere);
    }

/*-------------------------*\
 |*	Methode		    *|
 \*-------------------------*/

/**
 * Override
 * Call periodicly by the API
 *
 * Note : domaineMath pas use car pas zoomable
 */
void RayTracing::process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    Device::lastCudaError("RayTracing rgba uchar4 (before kernel)"); // facultatif, for debug only, remove for release

    //global mem
    //rayTracing<<<dg,db>>>(ptrDevPixels,w,h,t, ptrDevTabSphere,this->nbSphere);
    //constant mem
    //rayTracingToCM<<<dg,db>>>(ptrDevPixels,w,h,t,this->nbSphere);
    //shared mem
    rayTracing<<<dg,db,this->sizeOctet>>>(ptrDevPixels,w,h,t, ptrDevTabSphere,this->nbSphere);

    Device::lastCudaError("RayTracing rgba uchar4 (after kernel)"); // facultatif, for debug only, remove for release
    }

/**
 * Override
 * Call periodicly by the API
 */
void RayTracing::animationStep()
    {
    t += dt;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

