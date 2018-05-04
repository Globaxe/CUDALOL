#ifndef SHAPE_INDEXED_ANIMABLE_NODE_H_
#define SHAPE_INDEXED_ANIMABLE_NODE_H_
#include "ShapeIndexedGeomAnimable.h"
#include "ShapeIndexedNode.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL ShapeIndexedAnimableNode: public ShapeIndexedNode
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ShapeIndexedAnimableNode(string name,ShapeIndexedGeomAnimable* ptrShapeGeom);

	virtual ~ShapeIndexedAnimableNode();

	/*--------------------------------------*\
 |*		Surcharge		*|
	 \*-------------------------------------*/

	virtual void drawGeometry();

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
