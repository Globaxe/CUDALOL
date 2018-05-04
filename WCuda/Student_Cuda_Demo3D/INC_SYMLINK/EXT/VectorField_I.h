#ifndef VECTORFIELD_I_H_
#define VECTORFIELD_I_H_

#include "PrimitiveShape_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL VectorField_I : public PrimitiveShape_I
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	VectorField_I(unsigned int vectorSize, ColorFormat colorFormat);

	virtual ~VectorField_I();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public :

	inline unsigned int getVertorSize() const
	    {
	    return vectorSize;
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	const unsigned int vectorSize;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
