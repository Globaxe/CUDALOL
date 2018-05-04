#ifndef CORE_HEADER_ALGO_NORMALINDEXEDCOMPUTE_GPU_H_
#define CORE_HEADER_ALGO_NORMALINDEXEDCOMPUTE_GPU_H_

#include "envGLSurfaceCudas.h"
#include "NormalIndexedCompute_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class CBI_SURFACE_GL_CUDA NormalIndexedCompute: public NormalIndexedCompute_A
	{
	public:

	    NormalIndexedCompute(unsigned int vertexCount, int maxTriangleIncidentPerVertex);

	    virtual ~NormalIndexedCompute();

	    /*--------------------------------------*\
 |*		Surcharge		*|
	     \*-------------------------------------*/

	    /*
	     * Compute TabTriangleVoisinage from the given tabElement
	     * elementCount % 3 =0!
	     */
	    void init(unsigned int* tabElement, unsigned int elementCount);

	    void compute(float* ptrTabVertexCoord, float* ptrTabVertexNormal, unsigned int vertexCount, unsigned int* tabElement, unsigned int elementCount);

	    /*--------------------------------------*\
	     |*		attributs		    *|
	     \*-------------------------------------*/

	private :
		unsigned int* ptrDevTabTriangleProximity;
		unsigned int* ptrDevTabTriangleCount;

	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
