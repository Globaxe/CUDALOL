#ifndef GLIMAGEFACTORY_I_H_
#define GLIMAGEFACTORY_I_H_

#include "GLImage_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class GLImageFactory_I
    {
    public:
	
	virtual GLImage_I* create() =0;
	
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
