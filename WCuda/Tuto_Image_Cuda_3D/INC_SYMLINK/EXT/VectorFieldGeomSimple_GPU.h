#ifndef VECTORFIELDGEOMSIMPLE_GPU_H_
#define VECTORFIELDGEOMSIMPLE_GPU_H_

#include "envScene3dGL_Cuda.h"
#include "VectorFieldGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class CBI_SCENE3D_GL_CUDA VectorFieldGeomSimple: public VectorFieldGeom
	{

	    /*--------------------------------------*\
		 |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    VectorFieldGeomSimple(VectorField_I* ptrVectorField);

	    virtual ~VectorFieldGeomSimple();

	};
    }
#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
