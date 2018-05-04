#include <iostream>
#include "ABC.h"
#include "Quadratique.h"
#include "assert.h"
#include "AlgoA.h"
#include "AlgoB.h"
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/
int main(int argc, char **argv)
    {
    /*ABC abc(2.0, -4.0, 2.0);
    Quadratique quadratique(abc);
    int nbSolutions = quadratique.solve();
    double* tabX = quadratique.getTabX();
    for (int i=0;i< nbSolutions;i++)
	{
	cout << tabX[i] << endl;
	}*/
    ABC abc1(3,3,-6);
    Quadratique quad1(abc1);
    ABC abc2(2,-4,2);
    Quadratique quad2(abc2);
    ABC abc3(1,1,1);
    Quadratique quad3(abc3);
    double* tabX = quad1.getTabX();
    assert(tabX[0]==1&&tabX[1]==-2);
    tabX = quad2.getTabX();
    assert(tabX[0]==1);
    assert(quad3.solve()==0);

    Algo* algoA = new AlgoA();
    Algo* algoB = new AlgoB();
    assert(algoB->use(1)==0);
    assert(algoA->use(1)==4);
    cout<<"Algo b :"<<algoB->use(1)<<" Algo a :"<<algoA->use(1);
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

