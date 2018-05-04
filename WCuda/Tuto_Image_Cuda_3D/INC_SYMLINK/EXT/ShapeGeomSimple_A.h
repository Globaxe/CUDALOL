#ifndef SHAPEGEOMSIMPLE_A_H_
#define SHAPEGEOMSIMPLE_A_H_
#include "ShapeGeom.h"
#include "VertexMode.h"
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Facade implementaion of ShapeGeom
 *
 *
 */
class CBI_SCENE3D_GL ShapeGeomSimple_A: public ShapeGeom
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

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
	ShapeGeomSimple_A(GLenum primitiveType, unsigned int vertexLength, unsigned int flags, BufferFactory_I* ptrBufferFactory);

	virtual ~ShapeGeomSimple_A();

	/*--------------------------------------*\
	|*		Surcharge		*|
	 \*-------------------------------------*/

    protected:

	virtual void initGL();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    protected:

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
