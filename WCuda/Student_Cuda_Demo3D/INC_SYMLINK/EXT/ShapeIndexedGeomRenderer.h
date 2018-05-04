#ifndef SHAPEINDEXEDGEOMRENDERER_H_
#define SHAPEINDEXEDGEOMRENDERER_H_

#include "Renderer_I.h"
#include "ShapeIndexedGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * OpenGL 2.0 ShapeGeomRenderer
 */
class CBI_SCENE3D_GL ShapeIndexedGeomRenderer: public Renderer_I<ShapeIndexedGeom>
    {
    public:

	/*--------------------------------------*\
 |*		Destructor		*|
	 \*-------------------------------------*/

    public:

	virtual ~ShapeIndexedGeomRenderer();

	/*--------------------------------------*\
 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	void draw(ShapeIndexedGeom* ptrShapeIndexedGeom);

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setSolidColor(bool isSolideColorEnable);

	/*--------------------------------------*\
	 |*		Is			*|
	 \*-------------------------------------*/

    public:

	inline bool isSolidColorEnable() const
	    {
	    return solidColor;
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	bool solidColor;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
