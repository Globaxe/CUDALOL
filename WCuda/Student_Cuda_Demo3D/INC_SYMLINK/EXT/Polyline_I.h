#ifndef POLYLINE_I_H_
#define POLYLINE_I_H_

#include "PrimitiveShape_I.h"
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL Polyline_I : public PrimitiveShape_I
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Polyline_I(unsigned int vertexSize, ColorFormat colorFormat,bool loop=false);

	virtual ~Polyline_I();


	/*--------------------------------------*\
	|*		Get			*|
	 \*-------------------------------------*/

    public:

	inline bool isLoop() const
	    {
	    return loop;
	    }

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	const bool loop;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
