#pragma once

#include "Image_I.h"
#include "Animable_I_CPU.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    template<typename T>
    class Provider_I
	{
	public:

	    virtual ~Provider_I()
		{
		//Rien
		}


	    /*--------------------------------------*\
	     |*		Methodes		*|
	     \*-------------------------------------*/

	public:

	    virtual Animable_I<T>* createAnimable(void)=0;

	    virtual Image_I* createImageGL(void)=0;
	};
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
