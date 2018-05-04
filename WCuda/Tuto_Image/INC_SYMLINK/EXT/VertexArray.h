#ifndef GL_VERTEX_ARRAY_H_
#define GL_VERTEX_ARRAY_H_

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
     * OpenGL buffer representation like VertexBufferObject or PixelBufferObject
     * OpenGL 3.0 -> 4.5
     * Official doc : https://www.opengl.org/sdk/docs/man4/
     * @author : joaquim.stahli@he-arc.ch
     */
    class CBI_GL VertexArray: public Object_A
	{

	public:

	    VertexArray();

	    /*--------------------------------------*\
 |*		Surcharge		*|
	     \*-------------------------------------*/

	protected:

	    virtual void initGL();

	    virtual void releaseGL();

	public:

	    virtual GLuint bind() const;

	    virtual void unBind() const;

	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
