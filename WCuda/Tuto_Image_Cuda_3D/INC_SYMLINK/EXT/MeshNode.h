#ifndef MESH_NODE_H_
#define MESH_NODE_H_

#include "MeshGeomBase.h"
#include "ShapeAnimableNode.h"
#include "MeshShader.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL MeshNode: public ShapeAnimableNode
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	MeshNode(string name,MeshGeomBase* ptrMeshShape);

	virtual ~MeshNode();

	/*--------------------------------------*\
 |*		Methodes		*|
	 \*-------------------------------------*/


	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	void init();

	void release();

	void paintPrimitives(Graphic2D& ptrGraphic2D);



    protected:

	virtual void boundChanged();

	virtual void startDrawing();

	virtual void stopDrawing();

	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public :

	Mesh_I* getMesh();

    protected :

	MeshGeomBase* getMeshShape();

	/*--------------------------------------*\
 |*		Attributs			*|
	 \*-------------------------------------*/

    protected:
	// Tools
	MeshShader meshShader;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
