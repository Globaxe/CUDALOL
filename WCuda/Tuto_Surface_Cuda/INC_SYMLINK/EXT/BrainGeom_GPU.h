#ifndef BRAINGEOM_GPU_H_
#define BRAINGEOM_GPU_H_

#include "envGLSurfaceCudas.h"
#include "BrainGeomBase.h"
#include "Brain_GPU.h"
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class CBI_SURFACE_GL_CUDA BrainGeom: public BrainGeomBase
	{
	    /*--------------------------------------*\
 |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    BrainGeom(Brain_I* ptrBrain);

	    virtual ~BrainGeom();
	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
