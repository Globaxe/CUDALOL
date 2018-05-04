#ifndef GLUT_WINDOW_SCENE_H_
#define GLUT_WINDOW_SCENE_H_

#include "envGLUTScene3D.h"
#include "Scene.h"
#include "GLUTWindow.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GLUT GLUTWindowScene: public GLUTWindow
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Create a GLUTWindow with GLUTWindowOption as follow :
	 *
	 * 	displayMode      : GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGBA
	 * 	actionOnClose    : GLUT_ACTION_CONTINUE_EXECUTION
	 * 	renderingContext : GLUT_USE_CURRENT_CONTEXT
	 *
	 * This constructor is usefull then multiple Shape are shared between Scene and Windows.
	 * Always use renderingContext GLUT_USE_CURRENT_CONTEXT when there is sharing OpenGL ressources between windows.
	 */
	GLUTWindowScene(Scene* ptrGLScene, string title, int w, int h, int px = 0, int py = 0);

	/**
	 * Always use renderingContext GLUT_USE_CURRENT_CONTEXT when there is sharing OpenGL ressources between windows.
	 */
	GLUTWindowScene(Scene* ptrGLScene, string title, GLUTWindowOption glutWindowOption, int w, int h, int px = 0, int py = 0);

	virtual ~GLUTWindowScene();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	//void idleFunc();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline Scene* getScene()
	    {
	    return (Scene*) getPtrDisplayable();
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
