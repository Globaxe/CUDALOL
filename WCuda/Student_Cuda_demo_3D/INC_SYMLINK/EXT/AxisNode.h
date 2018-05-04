#ifndef AXIS_NODE_H_
#define AXIS_NODE_H_

#include "AxisGeom.h"
#include "ShapeNode.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL AxisNode: public ShapeNode
    {
    public:

	AxisNode(string name, AxisGeom* ptrAxisGeom);

	AxisNode(string name);

	virtual ~AxisNode();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	bool destroyAxis;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
