#ifndef CORE_HEADER_GL_INPUTSETTING_H_
#define CORE_HEADER_GL_INPUTSETTING_H_

#include "envScene3dGL.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL InputSetting
    {
    public:

	InputSetting();

	/*--------------------------------------*\
 |*		Attributs		*|
	 \*-------------------------------------*/

    public :

	float fovyIncrement;
	float angleSpeed; //Radian
	float zoomZSpeed;

	// Selection Domaine
	float scaleSpeed;
	float translationSpeed;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
