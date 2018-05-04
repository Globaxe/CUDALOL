#ifndef VECTORFIELDNODE_H_
#define VECTORFIELDNODE_H_

#include "PrimitiveShapeNode.h"
#include "VectorFieldGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL VectorFieldNode : public PrimitiveShapeNode
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	VectorFieldNode(string name, VectorFieldGeom* ptrVectorFieldGeom);

	virtual ~VectorFieldNode();

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
