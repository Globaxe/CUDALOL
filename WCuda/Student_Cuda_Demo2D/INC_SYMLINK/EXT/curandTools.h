#pragma once

#include <curand_kernel.h>
#include "Indice1D.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 *  Utilisation:
 *  	(1) Fabriquer sur le device les generateurs parallels de nomber aleatoire : setup_kernel_rand
 *  	(2) Passer au kernel m�tier ces g�n�rateurs : ptrDevTabGeneratorThread
 *  	(3) Dans le kernel m�tier
 *  		 curandState generatorThread = ptrDevTabGeneratorThread[tid]; //Optimisation
 *  		 xAlea = curand_uniform(&generatorThread);
 * Hyp
 * 	(H1) Grid et block monodimensionnelle
 */
__global__ void setup_kernel_rand(curandState* ptrDevTabGeneratorThread, int deviceId);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void setup_kernel_rand(curandState* ptrDevTabGeneratorThread, int deviceId)
    {
    int tid = Indice1D::tid();

    // Customisation du generator: Proposition (au lecteur de faire mieux)
    // Contrainte : Doit etre diff�rent d'un GPU � l'autre
    int deltaSeed = deviceId * INT_MAX;
    int deltaSequence = deviceId * 100;
    int deltaOffset = deviceId * 100;

    int seed = 1234 + deltaSeed;    // deviceId+tid;
    int sequenceNumber = tid + deltaSequence;    // + tid;
    int offset = deltaOffset;

    //Each thread gets same seed , a different sequence number , no offset
    curand_init(seed, sequenceNumber, offset, &ptrDevTabGeneratorThread[tid]);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
