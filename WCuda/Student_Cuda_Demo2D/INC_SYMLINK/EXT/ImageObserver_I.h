#ifndef IMAGE_OBSERVER_I_H
#define IMAGE_OBSERVER_I_H

#include "envGLImage.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_GLIMAGE ImageObserver_I
    {
    public:
	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

	virtual ~ImageObserver_I()
	    {
	    // Nothing
	    }
	
	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	virtual void onImageUpdate()=0;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/