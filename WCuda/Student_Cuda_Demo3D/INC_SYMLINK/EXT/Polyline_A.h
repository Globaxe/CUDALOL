#ifndef POLYLINE_A_H_
#define POLYLINE_A_H_

#include "Polyline_I.h"
#include "ShapeColorModel.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

template<typename Vertex, typename Color, ShapeColorModel CM, ColorType CT>
class Polyline_A: public Polyline_I
    {
	/*--------------------------------------*\
		 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Polyline_A(unsigned int vertexSize, bool loop = false) :
		Polyline_I(vertexSize, createColorFormat(CM, CT), loop)
	    {

	    }

	virtual ~Polyline_A()
	    {
	    // Nothing
	    }

	/*--------------------------------------*\
		 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	void fillRawVertex(void* tabVertex, void* tabColor)
	    {
	fillVertex((Vertex*) tabVertex, (Color*) tabColor, getVertexSize());
	    }

	/*--------------------------------------*\
		 |*		Methodes		*|
	 \*-------------------------------------*/

    protected:

	/*
	 * redefinir par l'utilisateur
	 */
	virtual void fillVertex(Vertex* tabVertex, Color* tabColor, unsigned int vertexSize)=0;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
