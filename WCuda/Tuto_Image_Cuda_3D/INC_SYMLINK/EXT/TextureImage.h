#ifndef TEXTUREIMAGE_H_
#define TEXTUREIMAGE_H_

#include "Texture_A.h"
#include "Image_I.h"
#include "ImageObserver_I.h"
#include "GLImageFactory_I.h"
#include "GLImage_A.h"
#include "Animatorable_I.h"



/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL TextureImage: public Texture_A, public Animatorable_I, public ImageObserver_I
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	TextureImage(Image_I* ptrImage, GLImageFactory_I* ptrGLImageFactory);

	virtual ~TextureImage();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    protected:

	virtual void initGL();

	virtual void releaseGL();

	virtual void fillTexture(gl::Texture* ptrTexture);

	virtual void updateGL();

    public:

	virtual void animationStep();

	virtual void onImageUpdate();


    private:

	void drawInTexture();

	void createTexture();

	void createFBO();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	Image_I* getImage() const
	    {
	    return ptrImage;
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Inputs
	Image_I* ptrImage;
	GLImage_I* ptrGLImage;

	// OpenGL
	GLuint fboID[1]; //FrameBufferObject

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
