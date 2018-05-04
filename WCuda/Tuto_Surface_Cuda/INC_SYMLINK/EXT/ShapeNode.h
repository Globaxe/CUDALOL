#ifndef SHAPE_NODE_H_
#define SHAPE_NODE_H_

#include "ShapeGeom.h"
#include "ShapeNode_A.h"
#include "ShapeGeomRenderer.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL ShapeNode: public ShapeNode_A
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ShapeNode(string name,ShapeGeom* ptrShapeGeom);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

    public:

	virtual ~ShapeNode();

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
	ShapeGeom* ptrShapeGeom;
	ShapeGeomRenderer shapeGeomRenderer;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
