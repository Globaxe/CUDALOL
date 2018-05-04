#ifndef BOUNDVIEWOPTION_H_
#define BOUNDVIEWOPTION_H_

#include "envScene3dGL.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL BoundViewOption
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	BoundViewOption(bool isAxisEnable = true, bool isCubeEnable = false, bool isSphereEnable = false,bool isParoisEnable=false,bool isGridParoisEnable=false,bool isCubeFileFerEnable=false);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    public:

	// Inputs
	bool isAxisEnable;
	bool isCubeEnable;
	bool isSphereEnable;
	bool isParoisEnable;
	bool isGridParoisEnable;
	bool isCubeFileFerEnable;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
