#ifndef NUAGEPOINTGEOMSIMPLE_GPU_H_
#define NUAGEPOINTGEOMSIMPLE_GPU_H_

#include "envScene3dGL_Cuda.h"
#include "NuagePointGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/
namespace gpu
    {

    class CBI_SCENE3D_GL_CUDA NuagePointGeomSimple: public NuagePointGeom
	{
	    /*--------------------------------------*\
	     |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    NuagePointGeomSimple(NuagePoints_I* ptrNuagePoints);

	    virtual ~NuagePointGeomSimple();

	};

    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
