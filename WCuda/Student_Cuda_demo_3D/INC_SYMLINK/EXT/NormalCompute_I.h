#ifndef ALGO_NORMALCOMPUTE_I_H_
#define ALGO_NORMALCOMPUTE_I_H_

#include "envGLSurface.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class NormalCompute_I
    {
    public:
	virtual ~NormalCompute_I() {}

	virtual void compute(float* ptrTabVertexCoord,float* ptrTabVertexNormal,unsigned int vertexCount)=0;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
