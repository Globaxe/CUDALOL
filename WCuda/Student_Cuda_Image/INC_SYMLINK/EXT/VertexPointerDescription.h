#ifndef GL_VERTEX_POINTER_DESCRIPTION_H_
#define GL_VERTEX_POINTER_DESCRIPTION_H_

#include "envBilatGL.h"
#include <GL/glew.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gl
    {
    /**
     * For OpenGL 2.0 compatibility
     * For OpenGL 3.0 use it in shader like that :
     *
     * 	COORDINATE (100)
     * 	VertexShaderCode :
     * 		layout(location = 100) in vec3 vertexCoordinate; // For forward compatibility
     *
     * 	COLOR (101)
     * 	VertexShaderCode :
     * 		layout(location = 101) in vec3 vertexColor;// For forward compatibility
     *
     * 	NORMAL (102)
     * 	VertexShaderCode :
     * 		layout(location = 102) in vec3 vertexNormal;// For forward compatibility
     */
    enum PointerTypeEnum
	{
	COORDINATE=100,
	COLOR=101,
	NORMAL=102,
	TEXTURECOORD=103
	};

    class CBI_GL VertexPointerDescription
	{
	    /*--------------------------------------*\
	 |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    /**
	     *
	     */
	    VertexPointerDescription(GLuint index=0, GLsizei size = 4, GLenum type = GL_FLOAT, GLboolean normalized = GL_FALSE, GLsizei stride = 0);

	    /*--------------------------------------*\
	 |*		Attributs		*|
	     \*-------------------------------------*/

	public:
	    // Inputs
	    GLuint index;
	    GLsizei size;
	    GLenum type;
	    GLboolean normalized;
	    GLsizei stride;

	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
