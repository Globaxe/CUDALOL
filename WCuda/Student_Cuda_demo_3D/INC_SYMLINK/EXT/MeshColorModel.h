#ifndef CORE_HEADER_MODEL_MESHCOLORMODEL_H_
#define CORE_HEADER_MODEL_MESHCOLORMODEL_H_

#include "envGLSurface.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/


enum MeshColorModel
    {
    RGBA,
    RGB,
    HSB,
    HSBA,
    H,
    HA,
    };


/**
 * 1,2,3 or 4
 * 0 if unknown
 */
CBI_SURFACE_GL unsigned int colorComponantCount(MeshColorModel colorModel);

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
