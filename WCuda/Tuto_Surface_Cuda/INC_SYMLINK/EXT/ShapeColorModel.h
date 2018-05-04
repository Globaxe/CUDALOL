#ifndef SHAPE_COLORMODEL_H_
#define SHAPE_COLORMODEL_H_

#include "envScene3dGL.h"
#include "ColorFormat.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

enum ShapeColorModel
    {
    COLOR_MODEL_RGBA,
    COLOR_MODEL_RGB,
    COLOR_MODEL_HSB,
    COLOR_MODEL_HSBA,
    COLOR_MODEL_HUE,
    COLOR_MODEL_HA,
    };


CBI_SCENE3D_GL ColorFormat createColorFormat(ShapeColorModel model,ColorType colorType);

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
