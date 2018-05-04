#ifndef CORE_HEADER_MODEL_CPU_NORMALTOOLS_GPU_H_
#define CORE_HEADER_MODEL_CPU_NORMALTOOLS_GPU_H_

#include "envGLSurfaceCudas.h"
#include "builtin_types.h"
#include <math.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class NormalTools
	{
	public:

	    /**
	     * return cross product ABxAC
	     */
	    __device__ static float3 crossProduct(float3 a, float3 b, float3 c)
		{
	    //A
	       float abx = a.x - b.x;
	       float aby = a.y - b.y;
	       float abz = a.z - b.z;

	       //B
	       float acx = a.x - c.x;
	       float acy = a.y - c.y;
	       float acz = a.z - c.z;

	       //cross product AxB
	       float nx = aby * acz - abz * acy;
	       float ny = abz * acx - abx * acz;
	       float nz = abx * acy - aby * acx;

	       return make_float3(nx, ny, nz);
		}

	    __device__ static void normalize(float3& n)
		{
		  float alpha=1.0f/norm(n);
		    n.x*=alpha;
		    n.y*=alpha;
		    n.z*=alpha;
		}

	    __device__ static float norm(const float3& n)
		{
		return sqrtf(n.x * n.x + n.y * n.y + n.z * n.z);
		}

	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
