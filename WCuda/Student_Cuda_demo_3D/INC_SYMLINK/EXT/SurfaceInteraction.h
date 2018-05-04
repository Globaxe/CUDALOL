#ifndef SURFACEINTERACTION_H_
#define SURFACEINTERACTION_H_

#include "NodeInteraction.h"
#include "ShapeNode_A.h"
#include "History.h"
#include "SurfaceScene.h"
#include "BoundCubeNode.h"

typedef History<Bound> BoundHistory;
typedef HistoryChangedListener_I<Bound> BoundHistoryListener;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL SurfaceInteraction: public NodeInteraction, BoundHistoryListener
    {

	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SurfaceInteraction(SurfaceScene* ptrSurfaceScene, ShapeNode_A* ptrSurfaceNode = NULL, InputSetting inputSetting = InputSetting());

	virtual ~SurfaceInteraction();

	/*--------------------------------------*\
 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	virtual void onHistoryChanged(const Bound& bound);

	virtual void onMouseMoved(const MouseEvent& event);

	virtual void onKeyPressed(const KeyEvent& event);

	virtual void onKeyReleased(const KeyEvent& event);

	virtual void drawPrimitives(Graphic2D& graphic2D);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    private:

	void toggleRenderMode();

	void selectionFinish();

	void selectionStart();

	void resetSelection();

	void computeTransformationBound(Bound& bound);

	void computeTransformationSelection();

	Bound computeSelectedBound(glm::vec3& t, glm::vec3& s);

	void drawHelpOverlay(Graphic2D& graphic2D);

	void drawSelectionHelpOverlay(Graphic2D& graphic2D);

	void drawDomaineOverlay(Graphic2D& graphic2D);

	/*--------------------------------------*\
 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setDomainOverlayEnable(bool isEnable);

	void setHelpOverlyEnable(bool isEnable);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline ShapeNode_A* getSurfaceNode()
	    {
	    return ptrSurfaceNode;
	    }

	/*--------------------------------------*\
 |*		Is			*|
	 \*-------------------------------------*/

    public:

	inline bool isDomaineOverlayEnable() const
	    {
	    return domaineOverlayEnable;
	    }

	inline bool isHelpOverlayEnable() const
	    {
	    return helpOverlayEnable;
	    }

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setSurfaceNode(ShapeNode_A* ptrSurfaceNode);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Inputs
	SurfaceScene* ptrSurfaceScene;
	ShapeNode_A* ptrSurfaceNode;

	BoundHistory boundHistory;

	//Selection
	BoundCubeNode* ptrBoundCubeSelection;
	bool isSelectionEnable;
	glm::vec3 scale;
	glm::vec3 translation;
	bool isSelectionScaleEnable;
	bool isSelectoinTranslationEnable;

	Transformation transformationSizeToBound;
	Transformation transformationSelection;

	bool domaineOverlayEnable;
	bool helpOverlayEnable;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
