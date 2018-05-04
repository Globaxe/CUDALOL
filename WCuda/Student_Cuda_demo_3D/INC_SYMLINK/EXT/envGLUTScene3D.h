/**
 * SceneGraphGLUT project
 * version : 0.0.1
 *
 * Cédric Bilat		cedric.bilat@he-arc.ch
 * Stähli Joaquim	joaquim.stahli@he-arc.ch
 */

//PRIVATE
#ifndef ENV_GLUT_SCENE_GRAPH_H_
#define ENV_GLUT_SCENE_GRAPH_H_

#include "dllHelper.h"

#ifdef CBI_SCENE3D_GLUT_DLL // defined if API is compiled as a DLL
    #ifdef CBI_SCENE3D_GLUT_EXPORT // defined if we are building the API DLL (instead of using it)
	#define CBI_SCENE3D_GLUT HELPER_DLL_EXPORT
    #else
	#define CBI_SCENE3D_GLUT HELPER_DLL_IMPORT
    #endif //CBI_SCENE_GRAPH_GLUT_DLL
    #define CBI_SCENE3D_GLUT_LOCAL HELPER_DLL_LOCAL
#else // CBI_SCENE_GRAPH_GLUT_DLL is not defined: this means API is a static lib.
    #define CBI_SCENE3D_GLUT
    #define CBI_SCENE3D_GLUT_LOCAL
#endif

#endif  /* ENV_GLUT_SCENE_GRAPH_H_ */
