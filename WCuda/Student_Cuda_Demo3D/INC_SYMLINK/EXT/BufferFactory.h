#ifndef BUFFERFACTORY_H_
#define BUFFERFACTORY_H_

#include "envScene3dGL.h"
#include "BufferFactory_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL BufferFactory: public BufferFactory_I
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    private:

	BufferFactory();

    public:

	virtual gl::Buffer* createVertexBuffer();

	virtual gl::Buffer* createElementBuffer();

	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public:

	static BufferFactory* getInstance();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	static BufferFactory* instance;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
