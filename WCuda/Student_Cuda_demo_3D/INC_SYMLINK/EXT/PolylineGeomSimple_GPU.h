#ifndef POLYLINEGEOMSIMPLE_GPU_H_
#define POLYLINEGEOMSIMPLE_GPU_H_

#include "envScene3dGL_Cuda.h"
#include "PolylineGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {

    class CBI_SCENE3D_GL_CUDA PolylineGeomSimple: public PolylineGeom
	{
	    /*--------------------------------------*\
	     |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    PolylineGeomSimple(Polyline_I* ptrPolyline);

	    virtual ~PolylineGeomSimple();
	};

    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
