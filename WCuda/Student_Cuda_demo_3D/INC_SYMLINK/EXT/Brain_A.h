#ifndef BRAIN_A_H_
#define BRAIN_A_H_

#include "Brain_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

template<typename Vertex, typename Color, MeshColorModel MeshColorModel, int ColorFormat, class DomaineMath>
class Brain_A: public Brain_I
    {
    public:

	Brain_A(BrainData& brainData) :
		Brain_I(brainData,MeshColorModel,ColorFormat)
	    {
	    // Nothing
	    }

	virtual ~Brain_A()
	    {
	    // Nothing
	    }

	/*--------------------------------------*\
 |*		Surcharge		*|
	 \*-------------------------------------*/

	// Override
	void fillRawVertex(void* prTabVertices, void* ptrDevTabColor)
	    {
	    fillVertex((Vertex*) prTabVertices, (Color*) ptrDevTabColor, vertexCount);
	    }

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	/*
	 * a redefinir par l'utilisateur (pas obligatoire)
	 */
	virtual void fillVertex(Vertex* prTabVertices, Color* ptrDevTabColor, unsigned int vertexCount)
	    {
	    // Nothing
	    }

	size_t getColorSize() const
	    {
	    return sizeof(Color);
	    }
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
