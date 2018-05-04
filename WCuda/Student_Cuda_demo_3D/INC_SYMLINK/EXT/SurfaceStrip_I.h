#ifndef CORE_HEADER_MODEL_SURFACESTRIP_I_H_
#define CORE_HEADER_MODEL_SURFACESTRIP_I_H_

#include "MeshIndexed_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * SurfaceStrip_I triangulations
 *
 * 	|/|/|/|/|/|/|	bande 1
 * 	|/|/|/|/|/|/|	bande 2
 * 	|/|/|/|/|/|/|	bande 3
 *
 * We store all the strip in one triangles strip using degenerated triangles
 *
 * Inspired by :
 *
 * 	http://www.learnopengles.com/tag/triangle-strips/
 */
class CBI_SURFACE_GL SurfaceStrip_I: public MeshIndexed_I
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SurfaceStrip_I(unsigned int nbVertexX, unsigned int nbVertexY, MeshColorModel colorModel, int colorFormat, const Bound& initialBound);

	virtual ~SurfaceStrip_I();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	/**
	 * tabElements is a CPU pointer!
	 */
	void initTriangles(unsigned int* tabElements, unsigned int elementCount);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    public:
	// Input
	const unsigned int nbVertexX;
	const unsigned int nbVertexY;

	static int MaxTriangleIncidentPerVertex;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
