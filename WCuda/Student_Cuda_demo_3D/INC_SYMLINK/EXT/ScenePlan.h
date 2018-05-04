#pragma once

#include "Scene.h"
#include "NodeInteraction.h"
#include "FinitePlane.h"
#include "Image_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class ScenePlan: public Scene
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ScenePlan();

	virtual ~ScenePlan();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	virtual void reshape(const Viewport& viewport);

	void add(Image_I* ptrImage, FinitePlane* ptrPlan);

	/*--------------------------------------*\
 |*		Methodes		*|
	 \*-------------------------------------*/

    private:

	void createCamera();

	void createGeometry();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Input
	Image_I* ptrImage;

	// Tools
	NodeInteraction* ptrNodeInteraction;
	GroupNode* ptrRootNode;
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
