#ifndef SURFACESTRIP_GEOM_CPU_H_
#define SURFACESTRIP_GEOM_CPU_H_

#include "SurfaceStripGeomBase.h"
#include "SurfaceStrip_CPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    class CBI_SURFACE_GL SurfaceStripGeom : public SurfaceStripGeomBase
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
