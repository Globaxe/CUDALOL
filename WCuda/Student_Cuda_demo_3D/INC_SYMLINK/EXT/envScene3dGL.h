/**
 * SceneGraph project
 * version : 0.0.1
 *
 * Cédric Bilat		cedric.bilat@he-arc.ch
 * Stähli Joaquim	joaquim.stahli@he-arc.ch
 */

//PRIVATE
#ifndef ENV_SCENE3D_GL_H
#define ENV_SCENE3D_GL_H

#include "dllHelper.h"

#ifdef CBI_SCENE3D_GL_DLL // defined if API is compiled as a DLL
    #ifdef CBI_SCENE3D_GL_EXPORT // defined if we are building the API DLL (instead of using it)
	#define CBI_SCENE3D_GL HELPER_DLL_EXPORT
    #else
	#define CBI_SCENE3D_GL HELPER_DLL_IMPORT
    #endif // CBI_SCENE3D_GL_EXPORT
    #define CBI_SCENE3D_GL_LOCAL HELPER_DLL_LOCAL
#else // CBI_SCENE3D_GL_DLL is not defined: this means API is a static lib.
    #define CBI_SCENE3D_GL
    #define CBI_SCENE3D_GL_LOCAL
#endif

#endif  /* ENV_SCENE3D_GL_H */
