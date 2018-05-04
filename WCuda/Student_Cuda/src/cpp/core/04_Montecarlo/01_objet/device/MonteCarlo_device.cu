#include "Indice2D.h"
#include "Indice1D.h"
#include "cudaTools.h"
#include <curand_kernel.h>
#include "reductionADD.h"
#include <stdio.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void monteCarlo(uint* ptrDevTabGM, curandState* ptrTabDevGeneratorGM, uint n);

__device__ float f(float x);

__device__ void useGenerator(curandState* tabDevGeneratorGM, uint n, uint tabSM[]);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * output : void required !!
 */
__global__ void monteCarlo(uint* ptrDevTabGM, curandState* ptrTabDevGeneratorGM, uint n)
    {
    extern __shared__ uint tabSM[];
    useGenerator(ptrTabDevGeneratorGM, n, tabSM);
    __syncthreads();
    reductionADD<uint>(tabSM, ptrDevTabGM);
    }

__global__
void createGenerator(curandState* tabDevGeneratorGM, int deviceId)
    {
    // Customisation du generator:
    // Proposition, au lecteur de faire mieux !
    // Contrainte : Doit etre différent d'un GPU à l'autre
    // Contrainte : Doit etre différent d’un thread à l’autre
    const int TID = Indice1D::tid();
    int deltaSeed = deviceId * INT_MAX / 10000;
    int deltaSequence = deviceId * 100;
    int deltaOffset = deviceId * 100;
    int seed = 1234 + deltaSeed;
    int sequenceNumber = TID + deltaSequence;
    int offset = deltaOffset;

    curand_init(seed, sequenceNumber, offset, &tabDevGeneratorGM[TID]);
    }

__device__
void useGenerator(curandState* tabDevGeneratorGM, uint n, uint tabSM[])
    {
    const int TID = Indice1D::tid();

    const int TID_LOCAL = Indice1D::tidLocal();

// Global Memory -> Register (optimization)
    curandState localGenerator = tabDevGeneratorGM[TID];
    float xAlea;
    float yAlea;

    uint nx = 0;
    for (long i = 1; i <= n; i++)
	{
	xAlea = curand_uniform(&localGenerator);
	yAlea = curand_uniform(&localGenerator);

	if (yAlea <= f(xAlea))
	    {
	    nx++;
	    }

	}

    //Register -> Global Memory
    //Necessaire si on veut utiliser notre generator
    // - dans d’autre kernel
    // - avec d’autres nombres aleatoires !

    tabSM[TID_LOCAL] = nx;
    tabDevGeneratorGM[TID] = localGenerator;
    }

__device__ float f(float x)
    {
    return 1. / (1 + x * x);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

