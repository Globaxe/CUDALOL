/**
 * GLTools project
 * version : 0.0.2
 *
 * Cédric Bilat		cedric.bilat@he-arc.ch
 * Stähli Joaquim	joaquim.stahli@he-arc.ch
 */

//PRIVATE
#ifndef ENV_SCENE_3D_GL_CUDA_H
#define ENV_SCENE_3D_GL_CUDA_H

#include "dllHelper.h"

#ifdef CBI_SCENE3D_GL_CUDA_DLL // defined if API is compiled as a DLL
    #ifdef CBI_SCENE3D_GL_CUDA_EXPORT // defined if we are building the API DLL (instead of using it)
	#define CBI_SCENE3D_GL_CUDA HELPER_DLL_EXPORT
    #else
	#define CBI_SCENE3D_GL_CUDA HELPER_DLL_IMPORT
    #endif // CBI_SCENE3D_GL_CUDA_EXPORT
    #define CBI_SCENE3D_GL_CUDA_LOCAL HELPER_DLL_LOCAL
#else // CBI_SCENE3D_GL_CUDA_DLL is not defined: this means API is a static lib.
    #define CBI_SCENE3D_GL_CUDA
    #define CBI_SCENE3D_GL_CUDA_LOCAL
#endif

#endif  /* ENV_SCENE_3D_GL_CUDA_H */
