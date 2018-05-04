#ifndef NODE_BOUND_CUBE_H_
#define NODE_BOUND_CUBE_H_

#include "CubeNode.h"
#include "ShapeIndexedNode.h"
#include "WiredCubeGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL BoundCubeNode: public Node_A
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	BoundCubeNode(string name, unsigned char color[4]);

	virtual ~BoundCubeNode();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	void init();

	void release();

	void draw();

	virtual Bound getBoundTransformed() const;

	virtual Bound getBound() const;

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Tools
	CubeNode* ptrCubeTransparant;
	WiredCubeGeom* ptrCubeFilFerGeom;
	ShapeIndexedNode* ptrCubeFilFer;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
