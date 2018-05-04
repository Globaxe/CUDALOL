#ifndef TEXTUREBLEND_H_
#define TEXTUREBLEND_H_

#include <GL/glew.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * OpenGL 2.0
 *
 * GL_TEXTURE_ENV_MODE :
 * 	GL_ADD, GL_MODULATE, GL_DECAL, GL_BLEND, GL_REPLACE, or GL_COMBINE
 */
enum TextureBlend
    {
    BLEND_REPLACE = GL_REPLACE,
    BLEND_COMBINE = GL_BLEND
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
