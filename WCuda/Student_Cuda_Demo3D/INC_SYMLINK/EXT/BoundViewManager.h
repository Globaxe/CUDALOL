#ifndef GLBOUNDVIEW_H_
#define GLBOUNDVIEW_H_


#include "WiredCubeGeom.h"
#include "BoundViewOption.h"
#include "BoundCubeNode.h"
#include "BoundParoisNode.h"
#include "CubeNode.h"
#include "AxisNode.h"
#include "CircleNode.h"
#include "GridNode.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL BoundViewManager
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	BoundViewManager(BoundViewOption boundViewOption=BoundViewOption());

	virtual ~BoundViewManager();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void draw(Node_A* ptrNode);

	void init();

	void release();

    private:

	void transformToBound(const Bound& bound);

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setBoundViewOption(BoundViewOption boundViewOption);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public :

	BoundViewOption* getBoundViewOption();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Inputs
	BoundViewOption boundViewOption;

	// Tools
	WiredCircleGeom* ptrWiredCircleGeom;
	WiredCubeGeom* ptrWiredCubeGeom;
	GridGeom* ptrGridGeom;

	GridNode* ptrGridNodeXY;
	GridNode* ptrGridNodeXZ;
	GridNode* ptrGridNodeYZ;
	CircleNode* ptrCircleHorizontalNode;
	CircleNode* ptrCircleVerticalNode;
	BoundCubeNode* ptrBoundCubeNode;
	BoundParoisNode* ptrBoundParoisNode;
	ShapeIndexedNode* ptrCubeFileFerNode;
	AxisNode* ptrAxisNode;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
