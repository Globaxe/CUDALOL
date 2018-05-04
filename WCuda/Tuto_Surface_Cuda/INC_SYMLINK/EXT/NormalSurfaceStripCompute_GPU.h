#ifndef CORE_HEADER_ALGO_NORMALSURFACESTRIPCOMPUTE_GPU_H_
#define CORE_HEADER_ALGO_NORMALSURFACESTRIPCOMPUTE_GPU_H_

#include "envGLSurfaceCudas.h"
#include "NormalIndexedCompute_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class CBI_SURFACE_GL_CUDA NormalSurfaceStripCompute: public NormalIndexedCompute_I
	{
	    /*--------------------------------------*\
 |*		Constructor		*|
	     \*-------------------------------------*/

	public:
	    NormalSurfaceStripCompute(unsigned int n, unsigned int m);

	    virtual ~NormalSurfaceStripCompute();

	    /*--------------------------------------*\
 |*		Surcharge		*|
	     \*-------------------------------------*/

	public:

	    void compute(float* ptrTabVertexCoord, float* ptrTabVertexNormal, unsigned int vertexCount, unsigned int* tabElement, unsigned int elementCount);

	    /*--------------------------------------*\
	     |*		Attributs		    *|
	     \*-------------------------------------*/

	private:

	    unsigned int n;
	    unsigned int m;

	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
