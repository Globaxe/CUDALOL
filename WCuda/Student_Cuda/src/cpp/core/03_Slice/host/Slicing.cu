#include <iostream>

#include "Device.h"
#include "Slicing.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void slicing(float* ptrTabGM,int n);
extern __global__ void slicingAdvanced(float* ptrTabGM,int n);

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

Slicing::Slicing(const Grid& grid,int n) : n(n)
    {
    //pour le simple
    //this->sizeOctetGM = n * sizeof(float);

    //pour le advanced
    this->sizeOctetGM = sizeof(float);

    result = 0;
    // MM
	{

	// MM (malloc Device)
	    {
	    Device::malloc(&ptrTabGM, sizeOctetGM);
	    Device::memclear(ptrTabGM, sizeOctetGM);
	    }
	}

    // Grid
	{
	this->dg = grid.dg;
	this->db = grid.db;
	}

	//pour le advanced
	this->sizeOctetSM = sizeof(float)*this->db.x;
    }

Slicing::~Slicing(void)
    {
    //MM (device free)
	{
	Device::free(ptrTabGM);
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void Slicing::run()
    {
    //version simple
//    slicing<<<dg,db>>>(ptrTabGM,n); // assynchrone

    //version advanced
    slicingAdvanced<<<dg,db,this->sizeOctetSM>>>(ptrTabGM,n);

    //version simple
//    float* ptrTab = new float[n];

    // MM (Device -> Host)
	{
	//advanced
	Device::memcpyDToH(&result, ptrTabGM, sizeOctetGM); // barriere synchronisation implicite

	//simple
//	Device::memcpyDToH(ptrTab, ptrTabGM, sizeOctetGM);
	}

      //version simple
//    for(int i = 0; i<n;i++)
//	{
//	result+=ptrTab[i];
//	}
//    result = result/(float)n;
//    delete ptrTab;

    }

float Slicing::getResult()
    {
    return this->result;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
