#ifndef SHAPEINDEXEDGEOMSIMPLE_CPU_H_
#define SHAPEINDEXEDGEOMSIMPLE_CPU_H_
#include "ShapeIndexedGeomSimple_A.h"
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    class CBI_SCENE3D_GL ShapeIndexedGeomSimple: public ShapeIndexedGeomSimple_A
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
	    ShapeIndexedGeomSimple(GLenum primitiveType, unsigned int vertexLength, unsigned int indexLenght, unsigned int flags);

	    virtual ~ShapeIndexedGeomSimple();

	};
    }
#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
