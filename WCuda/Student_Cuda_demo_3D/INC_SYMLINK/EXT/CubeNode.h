#ifndef NODE_CUBE_H_
#define NODE_CUBE_H_

#include "CubeGeom.h"
#include "ShapeNode.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Unit Cube center in (0,0,0)
 */
class CBI_SCENE3D_GL CubeNode: public ShapeNode
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	CubeNode(string name, CubeGeom* ptrCube);

	CubeNode(string name, CubeGeom* ptrCube, unsigned char color[4]);

	CubeNode(string name);

	CubeNode(string name, unsigned char color[4]);

	virtual ~CubeNode();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	bool destroyCube;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
