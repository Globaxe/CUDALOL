#ifndef SHAPEGEOMANIMABLESIMPLE_GPU_H_
#define SHAPEGEOMANIMABLESIMPLE_GPU_H_

#include "envScene3dGL_Cuda.h"
#include "ShapeGeomAnimableSimple_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class CBI_SCENE3D_GL_CUDA ShapeGeomAnimableSimple: public ShapeGeomAnimableSimple_A
	{

	    /*--------------------------------------*\
 |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    /**
	     * flags :
	     *  VertexMode::VERTEX_MODE_COORDINATE Mandatory!
	     *  VertexMode::VERTEX_MODE_COLOR_RGBA
	     *  VertexMode::VERTEX_MODE_NORMAL
	     *  VertexMode::VERTEX_MODE_TEXTURE
	     *  unsigned int flag= VERTEX_MODE_COORDINATE | VERTEX_MODE_NORMAL, ...
	     *
	     *  The order in the Buffer is the same
	     *  getBuffer(0) will get the VertexCoordinate Buffer.
	     */
	    ShapeGeomAnimableSimple(GLenum primitiveType, unsigned int vertexLength, unsigned int flags);

	    virtual ~ShapeGeomAnimableSimple();
	};

    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
