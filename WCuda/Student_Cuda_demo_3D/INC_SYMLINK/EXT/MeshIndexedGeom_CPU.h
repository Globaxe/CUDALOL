#ifndef MESH_INDEXED_SHAPE_GEOM_CPU_H_
#define MESH_INDEXED_SHAPE_GEOM_CPU_H_

#include "MeshIndexedGeomBase.h"
#include "MeshIndexed_CPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    class CBI_SURFACE_GL MeshIndexedGeom : public MeshIndexedGeomBase
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
