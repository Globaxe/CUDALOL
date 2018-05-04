#ifndef CIRCLENODE_H_
#define CIRCLENODE_H_

#include "WiredCircleGeom.h"
#include "ShapeNode.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Circle
 *  - center = (0,0,0)
 *  - rayon = 0.5 => diametre = 1
 *  - on plan XY, z=0
 */
class CBI_SCENE3D_GL CircleNode: public ShapeNode
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	CircleNode(string name, WiredCircleGeom* ptrWiredCircle);

	/**
	 * Create a new WiredCircleGeom, destructor will delete it.
	 */
	CircleNode(string name,int nbVertex=128);

	virtual ~CircleNode();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

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
