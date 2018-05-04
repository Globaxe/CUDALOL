#ifndef SHAPE_APPEARANCE_H_
#define SHAPE_APPEARANCE_H_
#include <GL/glew.h>

#include "envScene3dGL.h"
#include "TextureAppearance.h"
#include "Texture_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

enum RenderMode
    {
    RENDER_MODE_FILL = GL_FILL,
    RENDER_MODE_POINT = GL_POINT,
    RENDER_MODE_LINE = GL_LINE
    };

enum ClockWise
    {
    CLOCKWISE_CW = GL_CW,
    CLOCKWISE_CCW = GL_CCW
    };

class CBI_SCENE3D_GL ShapeAppearance
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ShapeAppearance(RenderMode renderMode = RENDER_MODE_FILL, ClockWise clockWise = CLOCKWISE_CCW);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline RenderMode getRenderMode() const
	    {
	    return renderMode;
	    }

	inline ClockWise getClockWis() const
	    {
	    return clockWise;
	    }

	inline float getLineWidth() const
	    {
	    return lineWidth;
	    }

	inline unsigned char* getColor()
	    {
	    return color;
	    }

	inline unsigned char getSininess() const
	    {
	    return shininess;
	    }

	inline Texture_A* getTexture()
	    {
	    return ptrTexture;
	    }

	inline TextureAppearance* getTextureAppearance()
	    {
	    return &textureAppearance;
	    }

	/*--------------------------------------*\
 |*		Is			*|
	 \*-------------------------------------*/

    public:

	inline bool isLightingEnable() const
	    {
	    return useLighting;
	    }

	/*
	 * if isOpaque is true mean no translucide object
	 * otherwise object maybe translucide
	 */
	inline bool isOpaque() const
	    {
	    return opaque;
	    }

	/**
	 * solidColor=true mean that there is only one color for each vertex!
	 */
	inline bool isSolidColor() const
	    {
	    return solidColor;
	    }

	inline bool isTextureEnable() const
	    {
	    return textureEnable;
	    }

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setRenderMode(RenderMode renderMode);

	void setClockWise(ClockWise clockWise);

	void setLightingEnable(bool isEnable);

	void setLineWidth(float lineWidth);

	void setColor(unsigned char color[4]);

	void setOpaque(bool isOpaque);

	void setSolidColorEnable(bool isEnable);

	/**
	 * Shininess in [0,128]
	 */
	void setShininess(unsigned char shininess);

	void setTextureEnable(bool textureEnable);

	void setTexture(Texture_A* ptrTexture);

	void setTextureAppearance(TextureAppearance textureAppearance);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	RenderMode renderMode;
	ClockWise clockWise;
	bool useLighting;
	float lineWidth;
	unsigned char color[4];
	unsigned char shininess;
	bool opaque;
	bool solidColor;
	bool textureEnable;
	Texture_A* ptrTexture;
	TextureAppearance textureAppearance;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
