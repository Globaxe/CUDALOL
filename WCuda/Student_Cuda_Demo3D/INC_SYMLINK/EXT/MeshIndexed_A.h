#ifndef MESH_INDEXED_A_H_
#define MESH_INDEXED_A_H_

#include "MeshIndexed_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

template<typename Vertex, typename Color, MeshColorModel MeshColorModel, int ColorFormat, class DomaineMath>
class MeshIndexed_A: public MeshIndexed_I
    {
    public:

	MeshIndexed_A(unsigned int vertexCount, unsigned int triangleCount, const DomaineMath& initialDomaine,int maxTriangleIncidentPerVertex=12) :
		MeshIndexed_I(vertexCount,triangleCount, MeshColorModel, ColorFormat, initialDomaine.toBound(),maxTriangleIncidentPerVertex)
	    {
	    // Nothing
	    }

	virtual ~MeshIndexed_A()
	    {
	    // Nothing
	    }

	/*--------------------------------------*\
 |*		Surcharge		*|
	 \*-------------------------------------*/

    public :

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

    public :
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
