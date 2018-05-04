#pragma once

#include "cuda_runtime.h"
#include <iostream>

using std::ostream;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Grid
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/


    public:

	/**
	 * Pour pouvoir instancier tableau de Grid
	 */
	Grid(const dim3& dg = dim3(1, 1, 1), const dim3& db = dim3(1, 1, 1));

	/*--------------------------------------*\
 |*		Methodes		*|
	 \*-------------------------------------*/

    public :

	int threadCounts() const;

	int blockCounts() const;

	int threadByBlock() const;

	/**
	 * grid et block
	 */
	bool is1D();

	/**
	* grid et block
	*/
	bool is2D();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    public:

	dim3 dg;
	dim3 db;
    };

ostream& operator<<(ostream& stream, const Grid& grid);


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
