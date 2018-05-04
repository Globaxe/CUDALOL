#include "AddVector.h"

#include <iostream>

#include "Device.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void addVector(float* ptrDevV1, float* ptrDevV2, float* ptrDevW,int n);

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

AddVector::AddVector(const Grid& grid, float* ptrV1, float* ptrV2, float* ptrW, int n) :
	ptrV1(ptrV1), ptrV2(ptrV2), ptrW(ptrW), n(n)
    {
    this->sizeOctet = n * sizeof(float); // octet

    // MM
	{

	// MM (malloc Device)
	    {
	    Device::malloc(&ptrDevV1, sizeOctet);
	    Device::malloc(&ptrDevV2, sizeOctet);
	    Device::malloc(&ptrDevW, sizeOctet);
	    }

	// MM (copy Host->Device)
	    {
	    Device::memcpyHToD(ptrDevV1, ptrV1, sizeOctet);
	    Device::memcpyHToD(ptrDevV2, ptrV2, sizeOctet);
	    }

	Device::lastCudaError("AddVector MM (end allocation)"); // temp debug, facultatif
	}

    // Grid
	{
	this->dg = grid.dg;
	this->db = grid.db;
	}
    }

AddVector::~AddVector(void)
    {
    //MM (device free)
	{
	Device::free(ptrDevV1);
	Device::free(ptrDevV2);
	Device::free(ptrDevW);

	Device::lastCudaError("AddVector MM (end deallocation)"); // temp debug, facultatif
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void AddVector::run()
    {
    Device::lastCudaError("addVecteur (before)"); // temp debug
    addVector<<<dg,db>>>(ptrDevV1, ptrDevV2, ptrDevW, n); // assynchrone
    Device::lastCudaError("addVecteur (after)"); // temp debug

    //Device::synchronize(); // Temp,debug, only for printf in  GPU

    // MM (Device -> Host)
	{
	Device::memcpyDToH(ptrW, ptrDevW, sizeOctet); // barriere synchronisation implicite
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
