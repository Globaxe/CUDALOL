#ifndef CORE_HEADER_ALGO_NORMALINDEXEDCOMPUTE_CPU_H_
#define CORE_HEADER_ALGO_NORMALINDEXEDCOMPUTE_CPU_H_

#include "cudaType_CPU.h"
#include "NormalIndexedCompute_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {

    class CBI_SURFACE_GL NormalIndexedCompute: public NormalIndexedCompute_A
	{
	    /*--------------------------------------*\
	     |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    NormalIndexedCompute(unsigned int vertexCount, int maxTriangleIncidentPerVertex);

	    virtual ~NormalIndexedCompute();

	    /*--------------------------------------*\
	     |*		Surcharge		    *|
	     \*-------------------------------------*/

	public :

	    void compute(float* ptrTabVertexCoord, float* ptrTabVertexNormal, unsigned int vertexCount,unsigned int* tabElement,unsigned int elementCount);

	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
