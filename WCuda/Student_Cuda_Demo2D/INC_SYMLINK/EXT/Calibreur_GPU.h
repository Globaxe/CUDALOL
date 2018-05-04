#pragma once

#include "both_define.h"
#include "Interval_GPU.h"

namespace gpu
    {
    template<typename T>
    class Calibreur
	{
	public:

	    /*--------------------------------------*\
	|*		Constructor		*|
	     \*-------------------------------------*/

	    __BOTH__
	    Calibreur(const Interval<T>& input, const Interval<T>& output)
		{
		this->pente = (float) (output.b - output.a) / (float) (input.b - input.a);
		this->translation = output.a - pente * input.a;
		}
	    __BOTH__
	    Calibreur(T x1,T x2,T y1,T y2)
		{
		this->pente=(float)(y2-y1)/(float)(x2-x1);
		this->translation = y1-pente*x1;
		}

	    // constructeur copie automatique car pas pointeur dans
	    //	CalibreurF
	    //	IntervalF

	    __BOTH__
	    virtual ~Calibreur()
		{
		// rien
		}

	    /*--------------------------------------*\
	|*		Methodes		*|
	     \*-------------------------------------*/

	public:

	    __BOTH__
	    void calibrer(T* ptrvalue)
		{
		*ptrvalue = (T) ((float) *ptrvalue * pente + translation);
		}

	    __BOTH__
	    float getPente()
		{
		return this->pente;
		}

	    __BOTH__
	    float getTranslation()
		{
		return this->translation;
		}

	    /*--------------------------------------*\
	|*		Attributs		*|
	     \*-------------------------------------*/

	private:

	    // Output
	    float pente;
	    float translation;

	};

    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
