#pragma once

#include "cudaTools.h"
#include "Grid.h"

#include <curand_kernel.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class MonteCarlo
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	MonteCarlo(const Grid& grid, uint n, float m);

	virtual ~MonteCarlo(void);

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void run();

	float getPI();

	uint getN0();

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	dim3 dg;
	dim3 db;
	uint n;
	float m;

	// Inputs/Outputs
	float pi;
	float result;
	uint n0;
	uint nbThread;
	// Tools
	uint* ptrDevTabGM;
	curandState* ptrTabDevGeneratorGM;
	size_t sizeOctetGM;
	size_t sizeOctetSM;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
