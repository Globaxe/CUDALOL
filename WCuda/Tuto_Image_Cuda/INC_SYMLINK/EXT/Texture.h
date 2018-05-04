#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "Object_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gl
    {

    /**
     * OpenGL texture representation
     * OpenGL 2.0 -> 4.5
     * Official doc : https://www.opengl.org/sdk/docs/man4/
     * @author : joaquim.stahli@he-arc.ch
     */
    class CBI_GL Texture: public Object_A
	{
	    /*--------------------------------------*\
	     |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    /**
	     * GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D, or GL_TEXTURE_CUBE_MAP
	     */
	    Texture(GLenum target);

	    virtual ~Texture();

	    /*--------------------------------------*\
	     |*		Methodes		*|
	     \*-------------------------------------*/

	public:

	    void texImage2D(GLenum target,int level, int internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * data = 0);

	    /*--------------------------------------*\
	     |*		Surcharge		*|
	     \*-------------------------------------*/

	protected:

	    virtual void initGL();

	    virtual void releaseGL();

	public:

	    GLuint bind() const;
	    void unBind() const;

	    /*--------------------------------------*\
 |*		Get			*|
	     \*-------------------------------------*/

	public:

	    inline GLenum getTarget() const
		{
		return target;
		}

	    /*--------------------------------------*\
	 |*		Attributs		*|
	     \*-------------------------------------*/

	private:

	    GLenum target;

	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
