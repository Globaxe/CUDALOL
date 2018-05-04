#ifndef NUAGEPOINTGEOM_H_
#define NUAGEPOINTGEOM_H_

#include "PrimitiveShapeGeom.h"
#include "NuagePoints_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL NuagePointGeom: public PrimitiveShapeGeom
    {
    public:

	NuagePointGeom(NuagePoints_I* ptrNuagePoints, BufferFactory_I* ptrBufferFactory);

	virtual ~NuagePointGeom();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline NuagePoints_I* getNuagePoints()
	    {
	    return getPrimitiveShapeCast<NuagePoints_I>();
	    }
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
