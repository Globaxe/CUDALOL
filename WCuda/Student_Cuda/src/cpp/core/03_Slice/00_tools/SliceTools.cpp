#include <iostream>
#include <math.h>

#include "SliceTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

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
 |*		Constructeur		*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*	Methode	public (static)		*|
 \*-------------------------------------*/

bool SliceTools::isAddVector_Ok(float* ptrV1, float* ptrV2, float* ptrW, int n)
    {
    float* ptrResult = new float[n];

    addVectorCPU(ptrV1, ptrV2, ptrResult, n);
    bool isOk = isEquals(ptrResult, ptrW, n, 1e-6); // comparer version cpu (ptrResult) avec version gpu (ptrW)

    delete[] ptrResult;

    return isOk;
    }


/**
 * 1 2 3 4 5
 */
float* SliceTools::createV1(int n)
    {
    float* ptrV = new float[n];

    for (int i = 0; i < n; i++)
	{
	ptrV[i] = i + 1;
	}

    return ptrV;
    }

/**
 * 10 20 30 40 50
 */
float* SliceTools::createV2(int n)
    {
    float* ptrV = new float[n];

    for (int i = 0; i < n; i++)
	{
	ptrV[i] = (i + 1) * 10;
	}

    return ptrV;
    }

void SliceTools::print(float* ptrV, int n)
    {
    cout << endl;
    for (int i = 0; i < n; i++)
	{
	cout << ptrV[i] << "\t";
	}
    cout << endl;
    }

/*--------------------------------------*\
 |*	Methode	private (static)	*|
 \*-------------------------------------*/

/**
 * v1,v2,w same size
 */
void SliceTools::addVectorCPU(float* ptrV1, float* ptrV2, float* ptrW, int n)
    {
    for (int i = 0; i < n; i++)
	{
	ptrW[i] = ptrV1[i] + ptrV2[i];
	}
    }

/**
 * simple
 */
bool SliceTools::isEquals(float* ptrV1, float* ptrV2, int n, float epsilon)
    {
    for (int i = 1; i <= n; i++)
	{
	float delta = fabs(*ptrV1 - *ptrV2);

	if (delta > epsilon)
	    {
	    return false;
	    }

	ptrV1++;
	ptrV2++;
	}

    return true;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

