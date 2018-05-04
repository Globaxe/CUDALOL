#ifndef NUAGEPOINTGEOMSIMPLE_CPU_H_
#define NUAGEPOINTGEOMSIMPLE_CPU_H_

#include "NuagePointGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/
namespace cpu
    {

    class CBI_SCENE3D_GL NuagePointGeomSimple: public NuagePointGeom
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
