#ifndef SHAPEGEOMANIMABLESIMPLE_A_H_
#define SHAPEGEOMANIMABLESIMPLE_A_H_

#include "ShapeGeomAnimable.h"
#include "VertexMode.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL ShapeGeomAnimableSimple_A: public ShapeGeomAnimable
    {
    public:

	/**
	 * flags :
	 *  VertexMode::ENABLE_COORDINATE Mandatory!
	 *  VertexMode::ENABLE_COLOR_RGBA
	 *  VertexMode::ENABLE_NORMAL
	 *  VertexMode::ENABLE_TEXTURE
	 *  unsigned int flag= ENABLE_COORDINATE | ENABLE_NORMAL, ...
	 *
	 *  The order in the Buffer is the same
	 *  getBuffer(0) will get the VertexCoordinate Buffer.
	 */
	ShapeGeomAnimableSimple_A(GLenum primitiveType, unsigned int vertexLength, unsigned int flags, BufferFactory_I* ptrBufferFactory);

	virtual ~ShapeGeomAnimableSimple_A();

	/*--------------------------------------*\
	|*		Surcharge		*|
	 \*-------------------------------------*/

    protected:

	virtual void initGL();

	virtual void fillBufferGL();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	virtual void fillTabCoordinate(float* tabCoordinateXYZ, unsigned int vertexSize)=0;

	virtual void fillTabColor(unsigned char* tabColorRGBA, unsigned int vertexSize);

	virtual void fillTabNormal(float* tabNormalXYZ, float* tabVertexXYZ, unsigned int vertexSize);

	virtual void fillTabTextureCoord(float* tabTextureCoordXY, unsigned int vertexSize);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	unsigned int flags;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
