#pragma once

#include <limits.h>


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/**
 * http://pubs.opengroup.org/onlinepubs/009695399/basedefs/limits.h.html
 */
class LimitsTools
    {
    public:

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/


	LimitsTools();

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

	virtual ~LimitsTools();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	/**
	 * Be careful between linux and windows limits!
	 */
	static void rappelTypeSize(void);






    private:

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    public:

	static const short MAX_SHRT=SHRT_MAX;

	static const int MAX_INT=INT_MAX;

	static const long MAX_LONG=LONG_MAX;

	static const long long MAX_LLONG=LONG_MAX;

    };




/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
