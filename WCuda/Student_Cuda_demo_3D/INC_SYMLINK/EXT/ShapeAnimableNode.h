#ifndef SHAPE_ANIMABLE_NODE_H_
#define SHAPE_ANIMABLE_NODE_H_

#include "ShapeNode.h"
#include "ShapeGeomAnimable.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL ShapeAnimableNode: public ShapeNode
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ShapeAnimableNode(string name, ShapeGeomAnimable* ptrShapeGeom);

	virtual ~ShapeAnimableNode();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	virtual void drawGeometry();

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
