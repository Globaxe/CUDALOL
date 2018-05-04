#ifndef NUAGEPOINTS_I_H_
#define NUAGEPOINTS_I_H_

#include "PrimitiveShape_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL NuagePoints_I : public PrimitiveShape_I
    {

	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	NuagePoints_I(unsigned int vertexSize,ColorFormat colorFormat);

	virtual ~NuagePoints_I();


    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
