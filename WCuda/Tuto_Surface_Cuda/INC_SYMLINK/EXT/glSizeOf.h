#ifndef GLSIZEOF_H_
#define GLSIZEOF_H_

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
     * type is on of :
     * 	GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT, GL_UNSIGNED_SHORT, GL_INT, and GL_UNSIGNED_INT
     */
    size_t sizeOf(GLenum type);
    }


#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
