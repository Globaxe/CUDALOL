#pragma once

#include <math.h>
#include "MathTools.h"

#include "Calibreur_CPU.h"
#include "ColorTools_CPU.h"
using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class MandelbrotMath
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	MandelbrotMath() :
		calibreur(Interval<float>(20, 120), Interval<float>(0, 1))
	    {
	    }

	// constructeur copie automatique car pas pointeur dans
	//	DamierMath
	// 	calibreur
	// 	IntervalF

	virtual ~MandelbrotMath()
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void colorXY(uchar4* ptrColor, float x, float y, int n)
	    {
	    int i = f(x, y, n);

	    // update color
	    if(i<=n)
		{
		//float ou int ?
		float hue01 = i;
		calibreur.calibrer(&hue01);
		ColorTools::HSB_TO_RVB(hue01, ptrColor);
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

	int f(float x, float y, int n)
	    {
	    double a = 0;
	    double b = 0;
	    double aCopy;
	    int i;
	    for (i = 1; i <= n; ++i)
		{
		    aCopy = a;
		    a = (a*a-b*b)+x;
		    b = 2*aCopy*b+y;
		    if (a*a+b*b>4)
			break;
		}
	    return i;
	    }

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:


	// Tools
	Calibreur<float> calibreur;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
