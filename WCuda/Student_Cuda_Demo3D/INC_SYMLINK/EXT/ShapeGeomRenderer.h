#ifndef SHAPEGEOMRENDERER_H_
#define SHAPEGEOMRENDERER_H_

#include "Renderer_I.h"
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * OpenGL 2.0 ShapeGeomRenderer
 */
class CBI_SCENE3D_GL ShapeGeomRenderer: public Renderer_I<ShapeGeom>
    {

	/*--------------------------------------*\
 |*		Destructor		*|
	 \*-------------------------------------*/

    public:

	virtual ~ShapeGeomRenderer();

	/*--------------------------------------*\
 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	void draw(ShapeGeom* ptrShapeGeom);

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
