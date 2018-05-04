#pragma once

#include <math.h>
#include "MathTools.h"
#include "Sphere.h"
#include <stdio.h>

#include "ColorTools_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class RayTracingMath
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	__device__ RayTracingMath(float t, int nbSphere, Sphere* ptrDevTabSphere)
	    {
	    this->t = t;
	    this->nbSphere = nbSphere;
	    this->ptrDevTabSphere = ptrDevTabSphere;
	    }

	__device__
	          virtual ~RayTracingMath()
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	__device__
	void colorIJ(uchar4* ptrColor, float i, float j)
	    {
	    f(ptrColor, i, j);
	    ptrColor->w = 255;
	    }

	__device__
	void f(uchar4* ptrColor, float i, float j)
	    {
	    ptrColor->x = 0;
	    ptrColor->y = 0;
	    ptrColor->z = 0;

	    float hCarre;
	    float dz;
	    float distanceMin = 12000;

	    for (uint k = 0; k < nbSphere; k++)
		{
		hCarre = ptrDevTabSphere[k].hCarre(make_float2(i, j));
		dz = ptrDevTabSphere[k].dz(hCarre);
		if (ptrDevTabSphere[k].isEnDessous(hCarre) &&  ptrDevTabSphere[k].distance(dz) < distanceMin)
		    {
		    distanceMin = ptrDevTabSphere[k].distance(dz);
		    float hue = ptrDevTabSphere[k].hue(t);
		    float brightness = ptrDevTabSphere[k].brightness(ptrDevTabSphere[k].dz(hCarre));
		    ColorTools::HSB_TO_RVB(hue, 1.f, brightness, ptrColor);
		    }
		}
	    }

    private:

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Tools
	float t;
	int nbSphere;
	Sphere* ptrDevTabSphere;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
