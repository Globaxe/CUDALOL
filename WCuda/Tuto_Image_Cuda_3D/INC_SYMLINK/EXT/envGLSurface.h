/**
 * GLTools project
 * version : 0.0.2
 *
 * C�dric Bilat		cedric.bilat@he-arc.ch
 * St�hli Joaquim	joaquim.stahli@he-arc.ch
 */

//PRIVATE
#ifndef ENV_SURFACE_GL_H
#define ENV_SURFACE_GL_H

#include "dllHelper.h"

#ifdef CBI_SURFACE_GL_DLL // defined if API is compiled as a DLL
    #ifdef CBI_SURFACE_GL_EXPORT // defined if we are building the API DLL (instead of using it)
	#define CBI_SURFACE_GL HELPER_DLL_EXPORT
    #else
	#define CBI_SURFACE_GL HELPER_DLL_IMPORT
    #endif // GLIMAGE_DLL_EXPORT
    #define CBI_SURFACE_GL_LOCAL HELPER_DLL_LOCAL
#else // GLIMAGE_USE_DLL is not defined: this means API is a static lib.
    #define CBI_SURFACE_GL
    #define CBI_SURFACE_GL_LOCAL
#endif

#endif  /* ENV_GLIMAGE_H */
