#ifndef MESH_INDEXED_SHAPE_GEOM_GPU_H_
#define MESH_INDEXED_SHAPE_GEOM_GPU_H_

#include "envGLSurfaceCudas.h"
#include "MeshIndexedGeomBase.h"
#include "MeshIndexed_GPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class CBI_SURFACE_GL_CUDA MeshIndexedGeom : public MeshIndexedGeomBase
	{
	    /*--------------------------------------*\
	     |*		Constructor		*|
	     \*-------------------------------------*/

	public:
	    MeshIndexedGeom(MeshIndexed_I* ptrMesh);

	    virtual ~MeshIndexedGeom();
	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
