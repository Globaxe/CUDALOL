#pragma once

#include "SurfaceStrip_I.h"
#include "SurfaceStripGeom_GPU.h"
#include "SurfaceStripNode.h"
#include "SurfaceInteraction.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class SurfaceSceneStrip: public SurfaceScene
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SurfaceSceneStrip(SurfaceStrip_I* ptrSurfaceStrip);

	virtual ~SurfaceSceneStrip();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * RENDER_MODE_FILL
	 * RENDER_MODE_POINT
	 * RENDER_MODE_LINE
	 */
	void setAppearance(RenderMode renderMode);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// INput
	SurfaceStrip_I* ptrSurfaceStrip;			 // Model

	// Tools
	gpu::SurfaceStripGeom* ptrSurfaceGeom;		 // Geometry
	SurfaceStripNode* ptrSurfaceNode;		 // Node
	SurfaceInteraction* ptrSurfaceInteraction;	 // Interaction

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
