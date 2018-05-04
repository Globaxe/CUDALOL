#include <iostream>

#include "Device.h"

#include "MonteCarloMultiGPU.h"
#include "MonteCarlo.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void monteCarlo(float* ptrDevTabGM, uint n);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

MonteCarloMultiGPU::MonteCarloMultiGPU(const Grid& grid, uint n, float m)
    {
    this->grid = grid;
    this->n = n;
    this->m = m;
    this->pi = 0;
    }

MonteCarloMultiGPU::~MonteCarloMultiGPU(void)
    {

    }
/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void MonteCarloMultiGPU::run()
    {
    uint n0 = 0;

#pragma omp parallel for reduction(+:n0)
    for (int deviceId = 0; deviceId < Device::getDeviceCount(); deviceId++)
	{
	Device::setDevice(deviceId);
	MonteCarlo montecarlo(grid, n/Device::getDeviceCount(), m);
	montecarlo.run();

	n0 += montecarlo.getN0();
	}

    pi = 4.f * n0 / n ;
    }

float MonteCarloMultiGPU::getPI()
    {
    return pi;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
