#pragma once

#include "cpptest.h"

#include "../../core/01_classe/Calculatrice.h"

class TestCalculatrice: public Test::Suite
    {

	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	TestCalculatrice(void);

	virtual ~TestCalculatrice();

	/*--------------------------------------*\
	 |*		Methode			*|
	 \*-------------------------------------*/

    private:

	void testAdd(void);

	void testMult(void);

	void testSub(void);

	void testGet(void);

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

