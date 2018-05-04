#ifndef WIRED_PAROIS_GEOM_H_
#define WIRED_PAROIS_GEOM_H_

#include "ShapeIndexedGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL WiredParoisGeom: public ShapeIndexedGeom
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	WiredParoisGeom();

	virtual ~WiredParoisGeom();

	/*--------------------------------------*\
 |*		Surcharge		*|
	 \*-------------------------------------*/

    protected:

	virtual void initGL();

    public:

	virtual Bound getBound() const;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
