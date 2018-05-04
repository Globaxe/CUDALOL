#ifndef POLYLINEGEOMSIMPLE_CPU_H_
#define POLYLINEGEOMSIMPLE_CPU_H_

#include "PolylineGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/
namespace cpu
    {

    class CBI_SCENE3D_GL PolylineGeomSimple: public PolylineGeom
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
