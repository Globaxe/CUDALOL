#ifndef BOUND_PAROIS_NODE_H_
#define BOUND_PAROIS_NODE_H_

#include "ParoisGeom.h"
#include "WiredParoisGeom.h"
#include "GroupNode.h"
#include "ShapeIndexedNode.h"
#include "ParoisNode.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL BoundParoisNode: public GroupNode
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/
    public:

	BoundParoisNode(string name,unsigned char color[4],WiredParoisGeom* ptrWiredParois,ParoisGeom* ptrParois);

	BoundParoisNode(string name,unsigned char color[4]);

	virtual ~BoundParoisNode();


	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Inputs
	WiredParoisGeom* ptrWiredParois;
	ParoisGeom* ptrParois;

	// Tools
	ParoisNode* ptrParoisTransparantNode;
	ShapeIndexedNode* ptrParoisFilFerNode;
	bool destroyGeom;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
