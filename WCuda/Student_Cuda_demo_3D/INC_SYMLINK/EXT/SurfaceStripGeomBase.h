#ifndef SURFACE_STRIP_GEOM_BASE_H_
#define SURFACE_STRIP_GEOM_BASE_H_

#include "envGLSurface.h"
#include "MeshIndexedGeomBase.h"
#include "SurfaceStrip_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL SurfaceStripGeomBase: public MeshIndexedGeomBase
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SurfaceStripGeomBase(SurfaceStrip_I* ptrSurfaceStrip, BufferFactory_I* ptrBufferFactory, NormalIndexedCompute_I* ptrNormalCompute);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

    public:

	virtual ~SurfaceStripGeomBase();

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
