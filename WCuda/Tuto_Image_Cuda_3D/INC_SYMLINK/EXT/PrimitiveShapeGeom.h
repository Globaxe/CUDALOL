#ifndef PRIMITIVE_SHAPE_GEOM_H_
#define PRIMITIVE_SHAPE_GEOM_H_

#include "ShapeGeomAnimable.h"
#include "PrimitiveShape_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL PrimitiveShapeGeom: public ShapeGeomAnimable
    {
    public:

	PrimitiveShapeGeom(GLenum primitiveType,PrimitiveShape_I* ptrPrimitiveShape, BufferFactory_I* ptrBufferFactory);

	virtual ~PrimitiveShapeGeom();

	/*--------------------------------------*\
	|*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	virtual void animationStep();

    protected:

	virtual void initGL();

	virtual void fillBufferGL();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	virtual Bound getBound() const;

	ColorFormat getColorFormat() const;

	inline PrimitiveShape_I* getPrimitiveShape()
	    {
	    return ptrPrimitiveShape;
	    }

	template<class T>
	inline T* getPrimitiveShapeCast()
	    {
	    return (T*) ptrPrimitiveShape;
	    }

    private:

	PrimitiveShape_I* ptrPrimitiveShape;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
