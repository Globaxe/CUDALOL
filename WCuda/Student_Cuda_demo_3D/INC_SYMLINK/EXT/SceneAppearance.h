#ifndef CORE_HEADER_GL_SCENEAPPEARANCE_H_
#define CORE_HEADER_GL_SCENEAPPEARANCE_H_
#include "envScene3dGL.h"
#include "BoundViewOption.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL SceneAppearance
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SceneAppearance();

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setLightDirection(float dir[4]);

	void setBackgroundColor(float colorRGBA[4]);

	void setAmbientLightColor(float colorRGBA[4]);

	void setBoundViewOption(const BoundViewOption& option);


	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public:

	float* getLightDirection();

	float* getBackgroundColor();

	float* getAmbientLightColor();


	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// IO
	float lightDirection[4];
	float backgroundColor[4];
	float ambientLightColor[4];

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
