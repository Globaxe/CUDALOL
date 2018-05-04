#pragma once

#include "both_define.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    template<typename T>
    class Interval
	{

	    /*--------------------------------------*\
	|*		Constructeur		*|
	     \*-------------------------------------*/

	public:

	    __BOTH__
	    Interval(T a, T b)
		{
		this->a = a;
		this->b = b;
		}

	    // constructeur copie automatique car pas pointeur dans
	    //	IntervalF

	    __BOTH__
	    virtual ~Interval()
		{
		// rien
		}

	    /*--------------------------------------*\
	|*		Methode			*|
	     \*-------------------------------------*/

	public:

	    __BOTH__
	    T getA(void)
		{
		return this->a;
		}

	    __BOTH__
	    T getB(void)
		{
		return this->b;
		}

	    __BOTH__
	    bool contain(T x)
		{
		return x>=a && x<=b;
		}

	    /*--------------------------------------*\
	|*		Attribut		*|
	     \*-------------------------------------*/

	public:

	    T a;
	    T b;
	};

    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
