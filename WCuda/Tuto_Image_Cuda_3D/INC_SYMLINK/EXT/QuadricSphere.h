#ifndef QUADRICSPHERE_H_
#define QUADRICSPHERE_H_

#include "Quadric.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL QuadricSphere: public Quadric
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	QuadricSphere(double radius, int slices, int stacks);

	/*--------------------------------------*\
 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	void drawQuadric();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline double getRadius() const
	    {
	    return radius;
	    }

	inline int getSlices() const
	    {
	    return slices;
	    }

	inline int getStacks() const
	    {
	    return stacks;
	    }

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public :

	void setRadius(double radius);

	void setSlices(int slices);

	void setStacks(int stacks);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	double radius;
	int slices;
	int stacks;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
