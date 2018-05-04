#ifndef CUDABUFFERFACTORY_H_
#define CUDABUFFERFACTORY_H_

#include "envGLSurfaceCudas.h"
#include "BufferFactory_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL_CUDA CudaBufferFactory: public BufferFactory_I
    {

	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    private:

	CudaBufferFactory();

	/*--------------------------------------*\
 |*		Destructor		*|
	 \*-------------------------------------*/

    public:

	virtual ~CudaBufferFactory();

	/*--------------------------------------*\
 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	gl::Buffer* createVertexBuffer();

	gl::Buffer* createElementBuffer();

	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public:

	static CudaBufferFactory* getInstance();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	static CudaBufferFactory* instance;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
