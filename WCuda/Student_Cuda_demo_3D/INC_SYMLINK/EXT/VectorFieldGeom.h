#ifndef VECTORFIELDGEOM_H_
#define VECTORFIELDGEOM_H_

#include "VectorField_I.h"
#include "PrimitiveShapeGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL VectorFieldGeom: public PrimitiveShapeGeom
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	VectorFieldGeom(VectorField_I* ptrVectorField, BufferFactory_I* ptrBufferFactory);

	virtual ~VectorFieldGeom();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	gl::Buffer* getBufferVertex();

	gl::Buffer* getBufferColor();


    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
