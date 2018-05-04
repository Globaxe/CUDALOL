#ifndef MESH_GEOM_BASE_H_
#define MESH_GEOM_BASE_H_

#include "envGLSurface.h"
#include "Mesh_I.h"
#include "NormalCompute_I.h"
#include "ShapeGeomAnimable.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL MeshGeomBase: public ShapeGeomAnimable
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	MeshGeomBase(Mesh_I* ptrMesh, BufferFactory_I* ptrBufferFactory,NormalCompute_I* ptrNormalCompute);

	virtual ~MeshGeomBase();

	/*--------------------------------------*\
	|*		Surcharge		*|
	 \*-------------------------------------*/

    protected:

	virtual void initGL();

	virtual void fillBufferGL();


    public:

	/**
	 * Call Periodically by API
	 */
	virtual void animationStep();

	virtual Bound getBound() const
	    {
	    return ptrMesh->getBound();
	    }

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    protected :

	virtual void initVertexBuffer();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public :

	inline Mesh_I* getMesh()
	    {
	    return ptrMesh;
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    protected:
	// Inputs
	Mesh_I* ptrMesh;
	NormalCompute_I* ptrNormalCompute;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
