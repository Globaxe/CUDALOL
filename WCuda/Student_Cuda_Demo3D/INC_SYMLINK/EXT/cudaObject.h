#ifndef CORE_HEADER_CUDA_CUDAOBJECT_H_
#define CORE_HEADER_CUDA_CUDAOBJECT_H_


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

#include "builtin_types.h"
#include "cuda_runtime.h"

#ifndef __BOTH__

#ifdef __CUDACC__
#define __BOTH__ __device__ __host__
#else
#define __BOTH__

#endif //__CUDACC__

#endif //__BOTH__

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
