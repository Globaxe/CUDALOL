#include <iostream>
#include "MonteCarlo.h"
#include "MonteCarloMultiGPU.h"
#include "Grid.h"
#include "Device.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

#include "host/MonteCarlo.h"

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useMonteCarlo(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useMonteCarlo()
    {
    uint n = 2000000000;
    float m = 1;

    // Partie interessante Cuda
	{
	// Grid cuda
	int mp = Device::getMPCount();
	int coreMP = Device::getCoreCountMP();

	dim3 dg = dim3(mp, 1, 1);  	// grid 1D pour simplifier la réduction intrathread
	dim3 db = dim3(coreMP, 1, 1);   	// bloc 1D pour simplifier la réduction intrathread
	Grid grid(dg, db);

	//MonteCarlo montecarlo(grid, n, m);
	MonteCarloMultiGPU montecarlo(grid, n, m);

	montecarlo.run();

	cout << "PI : " <<  montecarlo.getPI();
	}

    return 1;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

