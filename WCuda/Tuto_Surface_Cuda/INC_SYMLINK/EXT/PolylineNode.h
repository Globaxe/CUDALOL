#ifndef POLYLINENODE_H_
#define POLYLINENODE_H_

#include "PrimitiveShapeNode.h"
#include "PolylineGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL PolylineNode : public PrimitiveShapeNode
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public :

	PolylineNode(string name, PolylineGeom* ptrPolylineGeom);

	virtual ~PolylineNode();

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
