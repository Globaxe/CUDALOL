#include <iostream>
#include "SliceTools.h"
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

#include "host/Slice.h"

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useSlice(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useSlice()
    {
    int n = 9;

    // Partie interessante GPGPU
	{
	// Grid cuda
//	int mp = Device::getMPCount();
//	int coreMP = Device::getCoreCountMP();
//
//	dim3 dg = dim3(mp, 2, 1);  		// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
//	dim3 db = dim3(coreMP, 2, 1);   	// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
//	Grid grid(dg, db);

	dim3 dg = dim3(n, 1, 1);
	dim3 db = dim3(1, 1, 1);   	// deviceQuery dans terminal pour savoir valeur max
	Grid grid(dg, db);

	Slice slice(grid, n); // on passse la grille à AddVector pour pouvoir facilement la faire varier de l'extérieur (ici) pour trouver l'optimum
	slice.run();
	}

  //  SliceTools::print(ptrW, n); // check result

    //bool isOk = SliceTools::isAddVector_Ok(ptrV1, ptrV2, ptrW, n);

    //delete[] ptrV1;

    return 0;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

