#ifndef NUAGEPOINTS_A_H_
#define NUAGEPOINTS_A_H_

#include "NuagePoints_I.h"
#include "ShapeColorModel.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

template<typename Vertex, typename Color, ShapeColorModel CM,ColorType CT>
class NuagePoints_A: public NuagePoints_I
    {
    public:

	NuagePoints_A(unsigned int vertexSize) :
		NuagePoints_I(vertexSize,createColorFormat(CM,CT))
	    {

	    }

	virtual ~NuagePoints_A()
	    {
	    // Nothing
	    }

	/*--------------------------------------*\
 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	// Override
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
