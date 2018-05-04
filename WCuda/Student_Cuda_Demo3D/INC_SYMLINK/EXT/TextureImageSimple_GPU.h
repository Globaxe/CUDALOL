#ifndef TEXTUREIMAGESIMPLE_GPU_H_
#define TEXTUREIMAGESIMPLE_GPU_H_

#include "envScene3dGL_Cuda.h"
#include "TextureImage.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class CBI_SCENE3D_GL_CUDA TextureImageSimple : public TextureImage
	{
	    /*--------------------------------------*\
	     |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    TextureImageSimple(Image_I* ptrImage);

	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
