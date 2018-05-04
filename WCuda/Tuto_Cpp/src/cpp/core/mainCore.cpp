#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern void useHello(void);
extern void useDerivate(void);
extern void useStructure(void);
extern void useDestruction(void);
extern void usePolymorphisme(void);
extern void useTemplate();
extern void useSurchargeCout();
extern void useSurchargeAdd();
extern void useSurchargeCrochet();
extern void usePassage(void);
extern void useAllocation();
extern void useAdvancedSimple();
extern void useAdvanced();

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainCore(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainCore(void)
    {
    useHello();
    useDerivate();
    useStructure();
    useDestruction();
    usePolymorphisme();
    useTemplate();
    useSurchargeCout();
    useSurchargeAdd();
    useSurchargeCrochet();
    usePassage();
    useAllocation();
    useAdvancedSimple();
    useAdvanced();

    cout<<"\nend"<<endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

