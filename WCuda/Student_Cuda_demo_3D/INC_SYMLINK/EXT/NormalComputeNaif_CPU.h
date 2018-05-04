#ifndef CORE_HEADER_ALGO_NORMALCOMPUTENAIF_CPU_H_
#define CORE_HEADER_ALGO_NORMALCOMPUTENAIF_CPU_H_

#include "NormalCompute_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    /**
     * Naive normal computation
     * Browse vertex by triangle
     * Compute the normal vector of the triangle
     * each vertex having the same normal. (dont care neighbourhood)
     *
     * tabVertex { S1,S2,S3,S4,S5,S6} => 2 triangles
     */
    class CBI_SURFACE_GL NormalComputeNaif: public NormalCompute_I
	{
	    /*--------------------------------------*\
	     |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    virtual ~NormalComputeNaif();

	    /*--------------------------------------*\
	     |*		Surcharge		*|
	     \*-------------------------------------*/

	public:

	    void compute(float* ptrTabVertexCoord, float* ptrTabVertexNormal, unsigned int vertexCount);

	};
    }
#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
