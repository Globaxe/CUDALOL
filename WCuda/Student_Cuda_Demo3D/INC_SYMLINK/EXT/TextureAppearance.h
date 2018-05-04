#ifndef TEXTUREAPPEARANCE_H_
#define TEXTUREAPPEARANCE_H_

#include "envScene3dGL.h"
#include "TextureMode.h"
#include "TextureBlend.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL TextureAppearance
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	TextureAppearance(TextureMode textureMode = MODE_REPEAT, TextureBlend textureBlend = BLEND_REPLACE);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline TextureMode getTextureMode() const
	    {
	    return textureMode;
	    }

	inline TextureBlend getTextureBlend() const
	    {
	    return textureBlend;
	    }

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	/**
	 * textureMode :
	 * 	MODE_REPEAT
	 * 	MODE_MIRROR
	 * 	MODE_CLAMP
	 */
	void setTextureMode(TextureMode textureMode);

	/**
	 * textureBlend :
	 * 	BLEND_REPLACE, dont blend with geometry color
	 * 	BLEND_COMBINE, blend with geometry color
	 */
	void setTextureBlend(TextureBlend textureBlend);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	TextureMode textureMode;
	TextureBlend textureBlend;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
