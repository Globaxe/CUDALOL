#ifndef SURFACESTRIP_GEOM_GPU_H_
#define SURFACESTRIP_GEOM_GPU_H_

#include "envGLSurfaceCudas.h"
#include "SurfaceStripGeomBase.h"
#include "SurfaceStrip_GPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class CBI_SURFACE_GL_CUDA SurfaceStripGeom : public SurfaceStripGeomBase
	{
	    /*--------------------------------------*\
	     |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    SurfaceStripGeom(SurfaceStrip_I* ptrSurfaceStrip);

	    virtual ~SurfaceStripGeom();
	};
    }
#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
