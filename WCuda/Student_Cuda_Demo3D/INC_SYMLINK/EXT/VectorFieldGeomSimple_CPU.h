#ifndef VECTORFIELDGEOMSIMPLE_CPU_H_
#define VECTORFIELDGEOMSIMPLE_CPU_H_

#include "VectorFieldGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    class CBI_SCENE3D_GL VectorFieldGeomSimple: public VectorFieldGeom
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
