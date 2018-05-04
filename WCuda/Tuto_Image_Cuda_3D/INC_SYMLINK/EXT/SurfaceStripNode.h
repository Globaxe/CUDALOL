#ifndef SURFACESTRIPNODE_H_
#define SURFACESTRIPNODE_H_

#include "MeshIndexedNode.h"
#include "SurfaceStripGeomBase.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL SurfaceStripNode : public MeshIndexedNode
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SurfaceStripNode(string name,SurfaceStripGeomBase* ptrSurfaceStripGeom);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/


    public :

	virtual ~SurfaceStripNode();

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
