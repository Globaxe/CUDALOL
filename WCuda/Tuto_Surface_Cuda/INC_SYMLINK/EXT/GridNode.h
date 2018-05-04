#ifndef GRIDNODE_H_
#define GRIDNODE_H_

#include "GridGeom.h"
#include "ShapeNode.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * 2D grid plane oXY
 *
 * Sample with n=4 and m=3
 *
 * p=(-0.5,0.5f,0.0f)
 *  p_________  x
 *  |__|__|__|
 *  |__|__|__|
 *  |__|__|__|
 *  |__|__|__|
 *
 *  y
 */
class CBI_SCENE3D_GL GridNode: public ShapeNode
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/
    public:

	GridNode(string name, GridGeom* ptrGrid);

	GridNode(string name, unsigned int n = 1, unsigned int m = 1);

	virtual ~GridNode();


	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private :

	// Tools
	bool destroyGeom;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
