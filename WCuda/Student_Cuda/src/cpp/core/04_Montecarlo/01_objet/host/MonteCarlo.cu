#include <iostream>

#include "Device.h"

#include "MonteCarlo.h"
using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void monteCarlo(uint* ptrDevTabGM, curandState* ptrTabDevGeneratorGM, uint n);

extern __global__ void createGenerator(curandState* tabDevGeneratorGM,int deviceId);

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

MonteCarlo::MonteCarlo(const Grid& grid, uint n, float m) :
	n(n)
    {
    this->sizeOctetGM = sizeof(uint); // octet
    this->sizeOctetSM = grid.db.x * sizeof(uint); // octet

    this->m = m;
    this->pi = 0;
    this->result = 0;
    this->n0 = 0;
    this->nbThread = grid.threadCounts();
    this->nbThread = this->n / grid.threadCounts();
    this->n = this->nbThread * grid.threadCounts();
    size_t sizeOctetGeneratorGM = grid.threadCounts() * sizeof(curandState);
    // MM
	{

	// MM (malloc Device)
	    {
	    Device::malloc(&ptrDevTabGM, sizeOctetGM);
	    Device::memclear(ptrDevTabGM, sizeOctetGM);
	    Device::malloc(&ptrTabDevGeneratorGM, sizeOctetGeneratorGM);
	    }

	Device::lastCudaError("Slice MM (end allocation)"); // temp debug, facultatif
	}

    // Grid
	{
	this->dg = grid.dg;
	this->db = grid.db;
	}
    }

MonteCarlo::~MonteCarlo(void)
    {
    //MM (device free)
	{
	Device::free(ptrDevTabGM);
	Device::free(ptrTabDevGeneratorGM);
	Device::lastCudaError("Slice MM (end deallocation)"); // temp debug, facultatif
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void MonteCarlo::run()
    {
    Device::lastCudaError("slice (before)"); // temp debug
    createGenerator<<<dg,db>>>(ptrTabDevGeneratorGM, Device::getDeviceId()); // assynchrone
    monteCarlo<<<dg,db, this->sizeOctetSM>>>(ptrDevTabGM,ptrTabDevGeneratorGM , this->nbThread);// assynchrone
    Device::lastCudaError("slice (after)"); // temp debug

    //Device::synchronize(); // Temp,debug, only for printf in  GPU

    // MM (Device -> Host)
	{
	Device::memcpyDToH(&n0, ptrDevTabGM, sizeOctetGM); // barriere synchronisation implicite
	}
    cout << "n0 : " << n0 << "\n";
    cout << "n : " << n << "\n";
    pi = 4.f * n0 / n;
    }

float MonteCarlo::getPI()
    {
    return pi;
    }

uint MonteCarlo::getN0()
    {
    return n0;
    }
/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
