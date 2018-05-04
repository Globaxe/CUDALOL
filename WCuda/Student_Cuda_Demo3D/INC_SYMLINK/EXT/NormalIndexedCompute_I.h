#ifndef NORMALINDEXEDCOMPUTE_I_H_
#define NORMALINDEXEDCOMPUTE_I_H_

#include "envGLSurface.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class NormalIndexedCompute_I
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	virtual ~NormalIndexedCompute_I()
	    {
	    }

	/*--------------------------------------*\
 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*
	 * Compute TabTriangleVoisinage from the given tabElement
	 * elementCount % 3 =0!
	 */
	virtual void init(unsigned int* tabElement, unsigned int elementCount)
	    {
	    //empty by default
	    }

	virtual void compute(float* ptrTabVertexCoord, float* ptrTabVertexNormal, unsigned int vertexCount, unsigned int* tabElement,
		unsigned int elementCount)=0;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
