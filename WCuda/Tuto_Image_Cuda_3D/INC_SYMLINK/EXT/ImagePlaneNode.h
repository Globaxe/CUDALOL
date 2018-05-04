#ifndef IMAGE_PLANE_NODE_H_
#define IMAGE_PLANE_NODE_H_

#include "Image_I.h"
#include "FinitePlaneNode.h"
#include "TextureImage.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL ImagePlaneNode: public FinitePlaneNode
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ImagePlaneNode(string name, FinitePlaneGeom* ptrFinitePlaneGeom,TextureImage* ptrTextureImage);

	ImagePlaneNode(string name, FinitePlane* ptrFinitePlane,TextureImage* ptrTextureImage);

	virtual ~ImagePlaneNode();

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
