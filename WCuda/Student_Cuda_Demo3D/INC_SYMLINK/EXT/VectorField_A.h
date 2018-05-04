#ifndef VECTORFIELD_A_H_
#define VECTORFIELD_A_H_

#include "VectorField_I.h"
#include "ShapeColorModel.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

template<typename Vertex, typename Color, ShapeColorModel CM, ColorType CT>
class VectorField_A: public VectorField_I
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	VectorField_A(unsigned int vectorSize) :
		VectorField_I(vectorSize, createColorFormat(CM, CT))
	    {

	    }

	virtual ~VectorField_A()
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
