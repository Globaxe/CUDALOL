#ifndef CORE_HEADER_MODEL_SURFACESTRIP_A_H_
#define CORE_HEADER_MODEL_SURFACESTRIP_A_H_

#include "SurfaceStrip_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

template<typename Vertex, typename Color, MeshColorModel MeshColorModel, int ColorFormat, class DomaineMath>
class CBI_SURFACE_GL SurfaceStrip_A: public SurfaceStrip_I
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SurfaceStrip_A(unsigned int nbVertexX, unsigned int nbVertexY, const DomaineMath& initialDomaine) :
		SurfaceStrip_I(nbVertexX, nbVertexY, MeshColorModel, ColorFormat, initialDomaine.toBound())
	    {
	    // Nothing
	    }

	virtual ~SurfaceStrip_A()
	    {
	    // Nothing
	    }

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	void fillRawVertex(void* prTabVertices, void* ptrTabColor)
	    {
	    fillVertex((Vertex*) prTabVertices, (Color*) ptrTabColor, nbVertexX, nbVertexY, getBound());
	    }

	/*--------------------------------------*\
 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	virtual void fillVertex(Vertex* ptrDevVerticesCoord, Color* ptrDevVerticesColor, unsigned int nbVertexX, unsigned int nbVertexY, const DomaineMath& domainMath3D)=0;

	size_t getColorSize() const
	    {
	    return sizeof(Color);
	    }

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
