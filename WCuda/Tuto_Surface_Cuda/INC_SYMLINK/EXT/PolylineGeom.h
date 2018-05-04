#ifndef POLYLINEGEOM_H_
#define POLYLINEGEOM_H_

#include "PrimitiveShapeGeom.h"
#include "Polyline_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL PolylineGeom : public PrimitiveShapeGeom
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public :

	PolylineGeom(Polyline_I* ptrPolyline,BufferFactory_I* ptrBufferFactory);

	virtual ~PolylineGeom();


    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
