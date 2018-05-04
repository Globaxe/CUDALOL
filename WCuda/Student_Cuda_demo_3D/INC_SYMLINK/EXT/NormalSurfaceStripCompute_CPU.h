#ifndef CORE_HEADER_ALGO_NORMALSURFACESTRIPCOMPUTE_CPU_H_
#define CORE_HEADER_ALGO_NORMALSURFACESTRIPCOMPUTE_CPU_H_

#include "NormalIndexedCompute_I.h"
#include "cudaType_CPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    class CBI_SURFACE_GL NormalSurfaceStripCompute: public NormalIndexedCompute_I
	{

	    /*--------------------------------------*\
	     |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    NormalSurfaceStripCompute(unsigned int n,unsigned int m);

	    virtual ~NormalSurfaceStripCompute();

	    /*--------------------------------------*\
	     |*		Surcharge		*|
	     \*-------------------------------------*/

	public:

	    void compute(float* ptrTabVertexCoord, float* ptrTabVertexNormal, unsigned int vertexCount, unsigned int* tabElement, unsigned int elementCount);

	    /*--------------------------------------*\
	     |*		Methodes		*|
	     \*-------------------------------------*/

	private :

	    static void increment(cpu::float3* ptrA, const cpu::float3& b);

	    /*--------------------------------------*\
	     |*		Attributs		    *|
	     \*-------------------------------------*/

	private :

	    unsigned int n;
	    unsigned int m;


	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
