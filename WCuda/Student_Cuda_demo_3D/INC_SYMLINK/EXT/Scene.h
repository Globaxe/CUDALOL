#ifndef SCENE_H_
#define SCENE_H_

#include "envScene3dGL.h"

#include "Displayable_A.h"
#include "SceneAppearance.h"
#include "Viewport.h"
#include "Camera.h"
#include "CameraOrtho.h"
#include "CameraPerspective.h"
#include "InputSetting.h"
#include "MouseListener_I.h"
#include "KeyListener_I.h"
#include "BoundViewOption.h"
#include "GLPrimitiveDrawers.h"
#include "Graphic2D.h"
#include "GroupNode.h"
#include "BoundViewManager.h"

class NodeInteraction_A;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL Scene: public Displayable_A, MouseListener_I, KeyListener_I
    {
    public:

	Scene(Camera* ptrCamera = NULL, GroupNode* ptrRootNode = NULL, SceneAppearance appearance = SceneAppearance(), bool isAnimationEnable = true);

	virtual ~Scene();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void init(Panel_A &panel);

	void reshape(Panel_A &panel, int w, int h);

	void display(Panel_A &panel);

	void release(Panel_A &panel);

	virtual void onMouseMoved(const MouseEvent& event);

	virtual void onMousePressed(const MouseEvent& event);

	virtual void onMouseReleased(const MouseEvent& event);

	virtual void onMouseWheel(const MouseWheelEvent& event);

	virtual void onKeyPressed(const KeyEvent& event);

	virtual void onKeyReleased(const KeyEvent& event);

	/**
	 * Call periodically by the API
	 */
	void animationStep(Panel_A &panel,bool& isNeedUpdateView);

	virtual void animationStep();

    protected:

	virtual void init();

	virtual void reshape(const Viewport& viewport);

	virtual void startDisplay();

	virtual void display();

	virtual void stopDisplay();

	virtual void release();

	virtual void drawCamera();

	/**
	 * Clear all possible Buffers (GL_COLOR_BUFFER_BIT and GL_DEPTH_BUFFER_BIT and GL_STENCIL_BUFFER_BIT)
	 *
	 * glClear Possible value (OpenGL 4.5):
	 *
	 * 	GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT, and GL_STENCIL_BUFFER_BIT
	 *
	 * in OpenGL 2.0
	 *
	 * 	GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT, GL_ACCUM_BUFFER_BIT, and GL_STENCIL_BUFFER_BIT
	 *
	 * https://www.opengl.org/sdk/docs/man4/
	 */
	virtual void clearFrameBuffers();

	virtual void drawPrimitives(Graphic2D& graphic2D);

    private:

	virtual void drawPrimitives(Panel_A &panel);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	GroupNode* getRootNode();

	SceneAppearance* getAppearance();

	Camera* getCamera();

	NodeInteraction_A* getNodeInteraction();

	BoundViewOption* getBoundViewOption();

	/*--------------------------------------*\
 |*		Is			*|
	 \*-------------------------------------*/

    public:

	inline bool isAnimationEnable() const
	    {
	    return animationEnable;
	    }

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setRootNode(GroupNode* ptrRootNode);

	void setCamera(Camera* ptrCamera);

	void setBoundViewOption(const BoundViewOption& option);

	void setAppearance(SceneAppearance sceneAppearance);

	void setNodeInteraction(NodeInteraction_A* ptrPilote);

	void setAnimationEnable(bool animationEnable);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Inputs
	SceneAppearance appearance;
	GroupNode* ptrRootNode;
	Camera* ptrCamera;
	bool animationEnable;

	// Tools
	Viewport viewport;
	Graphic2D graphique2D;
	NodeInteraction_A* ptrPilote;
	//Transformation sceneTransformation;

	// OpenGL
	BoundViewManager boundViewManager;
	GLPrimitiveDrawers glPrimitiveDrawer;
    };

#include "NodeInteraction_A.h"


#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
