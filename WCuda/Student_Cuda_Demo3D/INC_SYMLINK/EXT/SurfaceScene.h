#ifndef SURFACESCENE_H_
#define SURFACESCENE_H_

#include "envGLSurface.h"
#include "Scene.h"
#include "ShapeNode_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL SurfaceScene: public Scene
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SurfaceScene(SceneAppearance appearance = SceneAppearance(), bool isAnimationEnable = true);

	virtual ~SurfaceScene();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	virtual void reshape(const Viewport& viewport);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	/**
	 * The default Perspective camera
	 */
	inline CameraPerspective* getSurfaceCamera()
	    {
	    return ptrCameraPerspective;
	    }


	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Tools
	CameraPerspective* ptrCameraPerspective;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
