#ifndef ALGO_NORMAL_INDEXED_COMPUTE_A_H_
#define ALGO_NORMAL_INDEXED_COMPUTE_A_H_

#include "NormalIndexedCompute_I.h"
#include "TabTriangleVoisinage.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*
 * None stateless algorithm
 * TabTriangleVoisinage is store and compute only once.
 * must call init everytime tabElement changed
 */
class CBI_SURFACE_GL NormalIndexedCompute_A : public NormalIndexedCompute_I
    {
    public:

	NormalIndexedCompute_A(unsigned int vertexCount, int maxTriangleIncidentPerVertex);

	virtual ~NormalIndexedCompute_A();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	/*
	 * Compute TabTriangleVoisinage from the given tabElement
	 * elementCount % 3 =0!
	 */
	virtual void init(unsigned int* tabElement, unsigned int elementCount);

	/*--------------------------------------*\
 |*		Attributs			*|
	 \*-------------------------------------*/

    protected:

	// Tools
	TabTriangleVoisinage tabTriangleVoisinage;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
