#ifndef MESH_INDEXED_I_H_
#define MESH_INDEXED_I_H_

#include "envGLSurface.h"
#include "Bound.h"
#include "MeshColorModel.h"
#include "Graphic2D.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL MeshIndexed_I
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	MeshIndexed_I(unsigned int vertexCount, unsigned int triangleCount, MeshColorModel colorModel, int colorFormat, const Bound& initialBound,
		int maxTriangleIncidentPerVertex = 12);

    protected:

	/**
	 *  constructor used for init all const attributs in subclasses
	 *  Used by SurfaceStrip_I where indexCount != triangleCount*3 !!
	 */
	MeshIndexed_I(unsigned int vertexCount, unsigned int triangleCount, unsigned int indexCount, MeshColorModel colorModel, int colorFormat,
		const Bound& initialBound, int maxTriangleIncidentPerVertex = 12);

	/*--------------------------------------*\
 |*		Destructor		*|
	 \*-------------------------------------*/

    public:

	virtual ~MeshIndexed_I();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * A redefinir par l'utilisateur
	 */
	virtual void fillRawVertex(void* prTabVertices, void* ptrDevTabColor)=0;

	/**
	 * tabElements is a CPU pointer!
	 */
	virtual void initTriangles(unsigned int* tabElements, unsigned int indexCount)=0;

	/**
	 * A redefinir par l'utilisateur
	 */
	virtual void paintPrimitives(Graphic2D& ptrGraphic2D);

	/**
	 * A redefinir par l'utilisateur
	 */
	virtual void animationStep(bool& isNeedUpdateView);

	virtual void onBoundChanged();

	/*--------------------------------------*\
	|*		Set			*|
	 \*-------------------------------------*/

    public:

	void setBound(const Bound& domaineMath);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline Bound getBound() const
	    {
	    return bound;
	    }

	/**
	 * 3 or 4
	 */
	unsigned int getColorComponantCount() const;

	virtual size_t getColorSize() const=0;

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    public:
	// Inputs
	const unsigned int triangleCount;
	const unsigned int vertexCount;
	const MeshColorModel colorModel;
	const int colorFormat; //GL_FLOAT, GL_UNSIGNED_BYTE
	const int maxTriangleIncidentPerVertex;

	// Tools
	const unsigned int indexCount;

    protected:
	// Inputs
	Bound bound;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
