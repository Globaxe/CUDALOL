#pragma once

#include <iostream>
#include <string>

#include "cuda_runtime.h"

using std::ostream;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class ChronoCuda
    {
    /*--------------------------------------*\
	 |*		Constructor		*|
     \*-------------------------------------*/

    public:

	/**
	 * start at creation
	 */
	ChronoCuda(cudaStream_t stream,string title);

	/**
	 * start at creation
	 */
	ChronoCuda(cudaStream_t stream);

	/**
	 * start at creation
	 */
	ChronoCuda();

	virtual ~ChronoCuda();


    /*--------------------------------------*\
     |*		Methodes		*|
     \*-------------------------------------*/

    private:

	void start();

    public :

	float stop() ;

	float getElapseTimeMS() ;

	void print(const string& titre) const;
	void print() const;
	void print(ostream& stream, const string& titre = "") const;

	/*--------------------------------------*\
	     |*		Friend			*|
	 \*-------------------------------------*/

	friend ostream& operator <<(ostream& stream, const ChronoCuda& chrono);

	/*--------------------------------------*\
	    |*		Attributs		*|
	 \*-------------------------------------*/

    public:

	// Input
	cudaStream_t stream;
	string title;

	// Outputs
	float elapseTimeMS;

	// Tools
	cudaEvent_t eventStart;
	cudaEvent_t eventStop;
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
