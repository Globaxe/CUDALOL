#ifndef MESH_GEOM_GPU_H_
#define MESH_GEOM_GPU_H_

#include "envGLSurfaceCudas.h"
#include "MeshGeomBase.h"
#include "Mesh_GPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class CBI_SURFACE_GL_CUDA MeshGeom: public MeshGeomBase
	{
	    /*--------------------------------------*\
	     |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    MeshGeom(Mesh_I* ptrMesh);

	    virtual ~MeshGeom();

	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
