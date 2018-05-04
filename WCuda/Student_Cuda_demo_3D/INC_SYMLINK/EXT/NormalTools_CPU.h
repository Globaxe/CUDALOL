#ifndef CORE_HEADER_MODEL_CPU_NORMALTOOLS_CPU_H_
#define CORE_HEADER_MODEL_CPU_NORMALTOOLS_CPU_H_

#include "cudaType_CPU.h"
#include "envGLSurface.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    class CBI_SURFACE_GL NormalTools
	{
	public:

	    /**
	     * return cross product ABxAC
	     */
	    static cpu::float3 crossProduct(cpu::float3 a, cpu::float3 b, cpu::float3 c);

	    static void normalize(cpu::float3& n);

	    static float norm(const cpu::float3& n);

	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
