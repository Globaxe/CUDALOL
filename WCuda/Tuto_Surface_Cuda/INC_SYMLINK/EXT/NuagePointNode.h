#ifndef NUAGEPOINTNODE_H_
#define NUAGEPOINTNODE_H_

#include "PrimitiveShapeNode.h"
#include "NuagePointGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL NuagePointNode: public PrimitiveShapeNode
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	NuagePointNode(string name, NuagePointGeom* ptrNuagePointGeom);

	virtual ~NuagePointNode();

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
