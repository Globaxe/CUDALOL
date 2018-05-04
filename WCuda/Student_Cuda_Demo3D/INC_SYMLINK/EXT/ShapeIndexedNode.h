#ifndef SHAPE_INDEXED_NODE_H_
#define SHAPE_INDEXED_NODE_H_

#include "ShapeIndexedGeom.h"
#include "ShapeNode_A.h"
#include "ShapeIndexedGeomRenderer.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL ShapeIndexedNode: public ShapeNode_A
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ShapeIndexedNode(string name,ShapeIndexedGeom* ptrShapeGeom);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

    public:

	virtual ~ShapeIndexedNode();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

	virtual void drawGeometry();

	virtual void init();

	virtual void release();


	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    protected:

	// Input
	ShapeIndexedGeom* ptrShapeGeom;
	ShapeIndexedGeomRenderer shapeIndexedGeomRenderer;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
