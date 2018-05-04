#ifndef CORE_HEADER_VIEW_GL_GLMESH_INDEXED_A_H_
#define CORE_HEADER_VIEW_GL_GLMESH_INDEXED_A_H_

#include "MeshIndexedGeomBase.h"
#include "envGLSurface.h"
#include "ShapeIndexedAnimableNode.h"
#include "MeshShader.h"
#include "FPSCounter.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL MeshIndexedNode: public ShapeIndexedAnimableNode
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	MeshIndexedNode(string name,MeshIndexedGeomBase* ptrMeshShape);


	/*--------------------------------------*\
 |*		Destructor		*|
	 \*-------------------------------------*/


    public :

	virtual ~MeshIndexedNode();


	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	virtual void init();

	virtual void release();

	virtual void paintPrimitives(Graphic2D& ptrGraphic2D);

	virtual void boundChanged();

    protected:

	virtual void startDrawing();

	virtual void stopDrawing();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public :

	MeshIndexed_I* getMesh();

    protected :

	MeshIndexedGeomBase* getMeshShape();



	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    protected:
	// Tools
	MeshShader meshShader;
	FPSCounter fpsCounter;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
