#pragma once

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported		*|
 \*-------------------------------------*/

#include "Indice1D.h"

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Hyp:
 * 	(H1) atomicAdd doit exister pour T , sinon utiliser la version in reductionADDLock.h
 * 	(H2) tabBlock size is a power of 2, >=64
 * 	(H3) tabBlock is already fill with data from reductionIntraThread
 * 	(H4) Grid et block 1D
 * 	(H5) ptrDevResultat already initialized with the correct value (by example from host with cudaMemset(...) or Device::memclear(...)
 */
template <typename T>
__device__ void reductionADD(T* tabBlock, T* ptrDevResultat);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

template <typename T>
static __device__ void reductionIntraBlock(T* tabBlock);

template <typename T>
static __device__ void reductionInterblock(T* tabBlock, T* ptrDevResultat);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

template <typename T>
__device__ void reductionADD(T* tabBlock, T* ptrDevResultat)
    {
    reductionIntraBlock(tabBlock);

    __syncthreads();

    reductionInterblock(tabBlock, ptrDevResultat);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Hyp :
 * 	(H1) 	length(tabBlock) est une puissance de 2 ! ie blockDim.x est une puissance de 2
 * 	(H2) 	grid et Block de dim 1
 * 	(H3) 	T est un type simple suppoter par atomicAdd
 *
 */
template <typename T>
__device__ void reductionIntraBlock(T* tabBlock)
    {

    //v1
//    int midle = blockDim.x / 2;
//    int tidLocal = threadIdx.x;
//
//    // int tidLocal =   Indice1D::tidLocal()
//
//    while (midle >= 1)
//	{
//
//	if (tidLocal < midle)
//	    {
//	    tabBlock[tidLocal] += tabBlock[tidLocal + midle];
//	    }
//
//	__syncthreads();
//
//	//midle /= 2;
//	midle>>=1;
//	}

//v2
    int midle = blockDim.x / 2;
    int tidLocal = threadIdx.x;

    //a 64 on ne divise plus et on a besoin de 32 thread pour finir de reduire le 64 premi�res cases
    while (midle >= 64)
	{

	if (tidLocal < midle)
	    {
	    tabBlock[tidLocal] += tabBlock[tidLocal + midle];
	    }

	__syncthreads();

	//midle /= 2;
	midle>>=1;
	}

    // midlde >=32. Dans le cas 32, la semantique est dans les 64 premières cases.

    // Utilisation des 32 thread d'un warp pour finir la reduction des 64 premières cases
    if(tidLocal<32) // semantique dans les 64 premieres cases
	{
	// no __syncthreads() necessary after each of the following lines as long as  we acces the data via a pointer decalred as volatile
	// because the 32 therad in each warp execute in a locked-step with each other
	volatile T* ptrData=tabBlock;

	ptrData[tidLocal]+=ptrData[tidLocal+32]; //  each thread of the warp execute this line in the same time. Aucun thread ne peut prendre de l'avance! A la fine de cette ligne, semantique dans les 32 premieres cases

	//if(tidLocal<16)		// pas necessaire car lecture(#) de ptrData[16] avant écriture(##) dans ptrData[16] ecriture ptrData[0]+=ptrData[16] (action #)  et ptrData[16]+=ptrData[32] (action ##)
	ptrData[tidLocal]+=ptrData[tidLocal+16]; //  Apres cette ligne semantique dans les 16 premières cases. Seuls les 16 premiers threads sont utiles

	//if(tidLocal<8)
	ptrData[tidLocal]+=ptrData[tidLocal+8];  //  Apres cette ligne semantique dans les 8 premières cases. Seuls les 8 premiers threads sont utiles

	//if(tidLocal<4)
	ptrData[tidLocal]+=ptrData[tidLocal+4];  // ...

	//if(tidLocal<2)
	ptrData[tidLocal]+=ptrData[tidLocal+2];

	//if(tidLocal<1)
	ptrData[tidLocal]+=ptrData[tidLocal+1];
	}

    }

/**
 *  Hyp : ptrDevResultat iniotaiulias� avec 0 !!
 */
template <typename T>
__device__ void reductionInterblock(T* tabBlock, T* ptrDevResultat)
    {
    if (threadIdx.x == 0)
	{
	atomicAdd(ptrDevResultat, tabBlock[0]); // autant d'acces que de block
	}
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
