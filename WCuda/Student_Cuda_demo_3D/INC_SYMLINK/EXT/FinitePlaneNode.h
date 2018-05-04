#ifndef FINITEPLANENODE_H_
#define FINITEPLANENODE_H_

#include "FinitePlaneGeom.h"
#include "ShapeAnimableNode.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL FinitePlaneNode: public ShapeAnimableNode
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	FinitePlaneNode(string name, FinitePlaneGeom* ptrFinitePlaneGeom);

	FinitePlaneNode(string name, FinitePlane* ptrFinitePlane);

	virtual ~FinitePlaneNode();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Tools
	bool destroyGeom;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
