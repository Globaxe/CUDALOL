#ifndef FINITEPLANEGEOM_H_
#define FINITEPLANEGEOM_H_

#include "FinitePlane.h"
#include "ShapeGeomAnimable.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL FinitePlaneGeom: public Observer_I<FinitePlane>, public ShapeGeomAnimable
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	FinitePlaneGeom(FinitePlane* ptrFinitePlane);

	virtual ~FinitePlaneGeom();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    protected:

	virtual void initGL();

	virtual void fillBufferGL();

    public:

	/**
	 * Called when FiniatePlane is updated
	 */
	virtual void onUpdate(FinitePlane* ptrPlane);

	virtual Bound getBound() const;

	/*--------------------------------------*\
 |*		Methodes		*|
	 \*-------------------------------------*/

    private:

	void computeBound();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Model
	FinitePlane* ptrFinitePlane;
	Bound boundPlane;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
