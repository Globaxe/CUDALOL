#ifndef PAROISNODE_H_
#define PAROISNODE_H_

#include "ParoisGeom.h"
#include "ShapeNode.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL ParoisNode : public ShapeNode
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ParoisNode(string name, ParoisGeom* ptrParois);

	/**
	 * Create a new Parois, destructor will delete it.
	 */
	ParoisNode(string name);

	virtual ~ParoisNode();

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
