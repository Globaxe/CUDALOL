#pragma once

#include <math.h>
#include "MathTools.h"

#include "Calibreur_GPU.h"
#include "ColorTools_GPU.h"

using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class MandelbrotMath
    {
	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:
	__device__
	MandelbrotMath(uint n) :
		calibreur(Interval<float>(0, n), Interval<float>(0, 1))
	    {
	    this->n = n;
	    }

	// constructeur copie: pas besoin car pas attribut ptr
	__device__
	virtual ~MandelbrotMath(void)
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	\*-------------------------------------*/

    public:
	__device__
	void colorXY(uchar4* ptrColor, float x, float y)
	    {
	    int k = f(x, y);
	    float hue;
	    if(k<n)
		{
		hue = (float)k;
		calibreur.calibrer(&hue);
		ColorTools::HSB_TO_RVB(hue, ptrColor); // update color
		}
	    else
		{
		ptrColor->x = 0;
		ptrColor->y = 0;
		ptrColor->z = 0;
		}

	    ptrColor->w = 255; // opaque
	    }

    private:
	__device__
	int f(float x, float y)
	    {
	    float a = 0.f;
	    float b = 0.f;
	    int k = 0;
	    while( !(a*a + b*b > 4 || k > n) )
		{
		float aCopy = a;
		a = (a*a - b*b) + x;
		b = 2*aCopy*b + y;
		k++;
		}
	    return k;
	    }

	/*--------------------------------------*\
	|*		Attribut		*|
	\*--------------------------------------*/

    private:

	// Input
	int n;

	// Tools
	Calibreur<float> calibreur;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
