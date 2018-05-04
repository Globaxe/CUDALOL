#ifndef SHAPE_GEOM_ANIMABLE_I_H_
#define SHAPE_GEOM_ANIMABLE_I_H_

#include "envScene3dGL.h"
#include "Animatorable_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL ShapeGeomAnimable_I : public Animatorable_I
    {

	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ShapeGeomAnimable_I();

	virtual ~ShapeGeomAnimable_I();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    protected:

	virtual void fillBufferGL()=0;

    public:

	void invokeLaterFillBufferGL();

	/**
	 * Call by api when needed
	 */
	void update();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	virtual void animationStep();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Tools
	bool needUpdate;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
