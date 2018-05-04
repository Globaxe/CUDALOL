#ifndef TEXTURE_A_H_
#define TEXTURE_A_H_

#include "Object_A.h"
#include "Texture.h"
#include "envScene3dGL.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Texture2D resource usable in a ShapeAppearance
 *
 * use :
 *
 * 	Texture_A texture;
 * 	texture.init();
 *
 * 	texture.bind();
 * 	texture.update(); //if needed
 * 	drawUsingTexture();
 * 	texture.unBind();
 */
class CBI_SCENE3D_GL Texture_A: public gl::Object_A
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Texture_A();

	virtual ~Texture_A();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    protected:

	/**
	 * Method used to fill fill the texture.
	 *
	 * for example :
	 *      //int level, int internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * data
	 * 	ptrTexture.texImage2D(0,GL_RGBA8,256,128,GL_RGBA, GL_UNSIGNED_BYTE, tabPixel);
	 */
	virtual void fillTexture(gl::Texture* ptrTexture)=0;

	virtual void updateGL()=0;

    public :

	void invokeLaterUpdateGL();

	/**
	 * Call updateGL if invokeLaterUpdateGL was called once.
	 */
	virtual void update();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    protected:

	virtual void initGL();

	virtual void releaseGL();

    public:

 	virtual GLuint bind() const;

 	virtual void unBind() const;

 	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public :

 	GLenum getTarget() const;

 	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    protected :

 	// Tools
	gl::Texture* ptrTexture;
	bool isNeedUpdate;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
