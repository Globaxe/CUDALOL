#ifndef MESH_INDEXED_GEOM_BASE_H
#define MESH_INDEXED_GEOM_BASE_H

#include "envGLSurface.h"
#include "ShapeIndexedGeom.h"
#include "ShapeIndexedGeomAnimable.h"
#include "NormalIndexedCompute_I.h"
#include "MeshIndexed_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL MeshIndexedGeomBase: public ShapeIndexedGeomAnimable
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	MeshIndexedGeomBase(MeshIndexed_I* ptrMesh, BufferFactory_I* ptrBufferFactory, NormalIndexedCompute_I* ptrNormalCompute);

    protected :

	MeshIndexedGeomBase(GLenum primitiveType,MeshIndexed_I* ptrMesh, BufferFactory_I* ptrBufferFactory, NormalIndexedCompute_I* ptrNormalCompute);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

    public :


	virtual ~MeshIndexedGeomBase();

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

    protected:

	virtual void initElementBuffer();

	virtual void initVertexBuffer();

	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public :

	inline MeshIndexed_I* getMesh()
	    {
	    return ptrMesh;
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    protected:
	// Inputs
	MeshIndexed_I* ptrMesh;
	NormalIndexedCompute_I* ptrNormalCompute;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
