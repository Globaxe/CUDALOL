#pragma once

#include "OpencvTools.h"
//#include "cudaTools.h"
#include "builtin_types.h"//cuda

using cv::Mat;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 *  see OpencvTools.h
 */
class OpencvTools_GPU: public OpencvTools
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	OpencvTools_GPU();

	virtual ~OpencvTools_GPU();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*-------------*\
	|* cast       *|
	 \*--------------*/


	static uchar4* castToUchar4(Mat& matRGBA);
	static uchar3* castToUchar3(Mat& matBGR);

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
