/**
 * GLTools Cuda project
 * version : 0.0.1
 *
 * Cédric Bilat		cedric.bilat@he-arc.ch
 * Stähli Joaquim	joaquim.stahli@he-arc.ch
 */

//PRIVATE
#ifndef ENV_BILAT_GL_CUDA_H_
#define ENV_BILAT_GL_CUDA_H_

#include "dllHelper.h"

#ifdef CBI_GL_CUDA_DLL // defined if API is compiled as a DLL
    #ifdef CBI_GL_CUDA_DLL_EXPORT // defined if we are building the API DLL (instead of using it)
	#define CBI_GL_CUDA HELPER_DLL_EXPORT
    #else
	#define CBI_GL_CUDA HELPER_DLL_IMPORT
    #endif //CBI_GL_CUDA_DLL_EXPORT
    #define CBI_GL_CUDA_LOCAL HELPER_DLL_LOCAL
#else // Static lib
    #define CBI_GL_CUDA
    #define CBI_GL_CUDA_LOCAL
#endif

#endif  /* ENV_GLIMAGE_H */
