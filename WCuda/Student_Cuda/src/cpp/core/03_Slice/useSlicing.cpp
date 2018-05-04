#include <iostream>
#include "VectorTools.h"
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

#include "host/Slicing.h"

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useSlicing(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useSlicing()
    {
    int n = INT_MAX/100;


    // Partie interessante GPGPU
	{
	//Grid cuda
	int mp = Device::getMPCount();
	int coreMP = Device::getCoreCountMP();

	//grille 1D pour advanced
	dim3 dg = dim3(512, 1, 1);  		// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
	dim3 db = dim3(512, 1, 1);   	// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
	Grid grid(dg, db);

	Slicing slicing(grid,n); // on passse la grille à Slicing pour pouvoir facilement la faire varier de l'extérieur (ici) pour trouver l'optimum
	slicing.run();
	cout<<"PI is : "<<slicing.getResult()<<endl;
	}
    return true;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

