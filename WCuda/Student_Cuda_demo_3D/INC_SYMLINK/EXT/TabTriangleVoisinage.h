#ifndef CORE_HEADER_MODEL_TABTRIANGLEVOISINAGE_H_
#define CORE_HEADER_MODEL_TABTRIANGLEVOISINAGE_H_

#include "envGLSurface.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL TabTriangleVoisinage
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	TabTriangleVoisinage(unsigned int vertexCount, int maxTriangleIncidentPerVertex);

	virtual ~TabTriangleVoisinage();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	void run(unsigned int* tabElement, unsigned int elementCount);

    private:

	void fillTabTrianglePoximityI(unsigned int a);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	unsigned int* getTabTriangleVoisinag()
	    {
	    return tabTriangleProximity;
	    }

	unsigned int* getTabTriangleCount()
	    {
	    return tabTriangleCount;
	    }

	inline int getMaxTriangleIncidentPerVertex() const
	    {
	    return maxTriangleIncidentPerVertex;
	    }

	inline int getVertexCount() const
	    {
	    return vertexCount;
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	unsigned int vertexCount;
	int maxTriangleIncidentPerVertex;
	unsigned int* tabTriangleProximity;
	unsigned int* tabTriangleCount;
	unsigned int nbTriangleIncidantMax;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
