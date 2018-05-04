#ifndef VERTEXMODE_H_
#define VERTEXMODE_H_

#include "envScene3dGL.h"
#include "VertexPointerDescription.h"
#include <vector>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

enum VertexMode
    {
    ENABLE_COORDINATE=1,//bitmask (0001)
    ENABLE_COLOR_RGBA=2,//bitmask (0010)
    ENABLE_NORMAL=4,//bitmask (0100)
    ENABLE_TEXTURE=8//bitmask (1000)
    };


// Tools
CBI_SCENE3D_GL bool isBitMaskEnable(unsigned int flags, VertexMode mask);

// Build
CBI_SCENE3D_GL std::vector<gl::VertexPointerDescription> computeVertexDescriptorTab(unsigned int flags);

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
