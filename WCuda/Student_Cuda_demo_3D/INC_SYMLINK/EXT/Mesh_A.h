#ifndef MESH_A_H_
#define MESH_A_H_

#include "Mesh_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

template<typename Vertex, typename Color, MeshColorModel MeshColorModel, int ColorFormat, class DomaineMath>
class Mesh_A: public Mesh_I
    {
    public:

	Mesh_A(unsigned int triangleCount, const DomaineMath& initialDomaine) :
		Mesh_I(triangleCount, MeshColorModel, ColorFormat, initialDomaine.toBound())
	    {
	    // Nothing
	    }

	virtual ~Mesh_A()
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

	// Override
	void onBoundChanged()
	    {
	    onDomaineChanged(getBound());
	    }

	/*--------------------------------------*\
     |*		Methodes		*|
	 \*-------------------------------------*/

	/*
	 * redefinir par l'utilisateur
	 */
	virtual void fillVertex(Vertex* prTabVertices, Color* ptrDevTabColor, unsigned int vertexCount)=0;

	/*
	 * redefinir par l'utilisateur
	 */
	virtual void onDomaineChanged(const DomaineMath& domaineMath)
	    {
	    // Rien
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
