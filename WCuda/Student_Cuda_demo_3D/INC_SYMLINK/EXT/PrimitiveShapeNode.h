#ifndef PRIMITIVE_SHAPE_NODE_H_
#define PRIMITIVE_SHAPE_NODE_H_

#include "envScene3dGL.h"
#include "ColorFormatFlatShader.h"
#include "ShapeAnimableNode.h"
#include "PrimitiveShapeGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL PrimitiveShapeNode: public ShapeAnimableNode
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	PrimitiveShapeNode(string name, PrimitiveShapeGeom* ptrPrimitiveShapeGeom);

	virtual ~PrimitiveShapeNode();

	/*--------------------------------------*\
 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	void init();

	void release();

    protected:

	virtual void startDrawing();

	virtual void stopDrawing();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public :

	PrimitiveShape_I* getPrimitiveShape();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    protected :

	ColorFormatFlatShader* ptrShaderColorFormatFlat;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
