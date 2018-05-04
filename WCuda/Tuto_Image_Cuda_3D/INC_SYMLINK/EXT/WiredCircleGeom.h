#ifndef WIRED_CIRCLE_GEOM_H_
#define WIRED_CIRCLE_GEOM_H_

#include "ShapeGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL WiredCircleGeom: public ShapeGeom
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	WiredCircleGeom(int subDivision=128);

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    protected:

	void initGL();

    public:

	virtual Bound getBound() const;

    private:

	/**
	 * Circle
	 *  - center = (0,0,0)
	 *  - rayon = 0.5 => diametre = 1
	 */
	static void fillSphereVertices(float* tabSphere, unsigned int nbVertexSphere);

    };
#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
