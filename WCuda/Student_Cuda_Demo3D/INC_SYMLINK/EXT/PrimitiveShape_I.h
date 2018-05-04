#ifndef PRIMITIVESHAPE_I_H_
#define PRIMITIVESHAPE_I_H_

#include "ColorFormat.h"
#include "Bound.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class PrimitiveShape_I
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	PrimitiveShape_I(unsigned int vertexSize, ColorFormat colorFormat);

	virtual ~PrimitiveShape_I();

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	virtual void fillRawVertex(void* prTabVertices, void* ptrTabColor)=0;

	virtual void animationStep(bool& isNeedUpdateView)=0;

	virtual Bound getBound() const=0;

	/*--------------------------------------*\
	|*		Get			*|
	 \*-------------------------------------*/

    public:

	inline unsigned int getVertexSize() const
	    {
	    return vertexSize;
	    }

	inline ColorFormat getColorFormat() const
	    {
	    return colorFormat;
	    }

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	const unsigned int vertexSize;
	const ColorFormat colorFormat;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
