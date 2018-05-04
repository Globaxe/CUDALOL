#ifndef COLORFORMAT_H_
#define COLORFORMAT_H_

#include "envScene3dGL.h"
#include <stdlib.h>


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

enum ColorMode
    {
    MODE_HSB,
    MODE_RGB
    };

enum ColorType
    {
    TYPE_FLOAT,
    TYPE_UCHAR
    };

class CBI_SCENE3D_GL ColorFormat
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ColorFormat(ColorMode mode, unsigned int nbComponante, ColorType type);

	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public :

	size_t sizeOf() const;

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    public:

	const ColorMode mode;
	/*
	 * value between [1 and 4]
	 */
	const unsigned int nbComponante;

	const ColorType type;

	/*--------------------------------------*\
	 |*		Static			*|
	 \*-------------------------------------*/

    public:
	const static ColorFormat RGBA_uchar4;
	const static ColorFormat RGBA_float4;
	const static ColorFormat RGB_uchar3;
	const static ColorFormat RGB_float3;
	const static ColorFormat HSB_float3;
	const static ColorFormat HSB_float4;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
