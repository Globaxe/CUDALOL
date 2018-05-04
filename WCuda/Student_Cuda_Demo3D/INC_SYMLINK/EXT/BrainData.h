#ifndef BRAIN_DATA_H_
#define BRAIN_DATA_H_

#include "envGLSurface.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

struct BrainData
    {
	float* tabVertices;
	unsigned int* tabTriangles;

	unsigned int vertexCount;
	unsigned int triangleCount;
	int maxTriangleIncidentPerVertex;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
