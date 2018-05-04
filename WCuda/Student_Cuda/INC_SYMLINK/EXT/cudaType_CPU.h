#ifndef CUDA_TYPE_CPU_H_
#define CUDA_TYPE_CPU_H_

//pragma once marche pas ici!

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

// Attention 	: code duplicated : aussi dans shared_lib api image
// Contrainte 	: Les deux versions doivent etre identique
//Define outsite namespace cpu due to conflict with OpenCV defines and using namespace cpu;
//coloration synthaxique ok

#ifndef uchar
typedef unsigned char uchar;
#endif

#ifndef uint
typedef unsigned int uint;
#endif

#ifndef ulong
typedef unsigned long ulong;
#endif

namespace cpu
    {
    /*--------------------------------------*\
    |*		float			*|
     \*-------------------------------------*/

    struct float2
	{
	    float x;
	    float y;
	};

    struct float3
	{
	    float x;
	    float y;
	    float z;
	};

    struct float4
	{
	    float x;
	    float y;
	    float z;
	    float w;
	};

    /*--------------------------------------*\
     |*		uchar			*|
     \*-------------------------------------*/

    struct uchar2
	{
	    unsigned char x;
	    unsigned char y;
	};

    struct uchar3
	{
	    unsigned char x;
	    unsigned char y;
	    unsigned char z;
	};

    struct uchar4
	{
	    unsigned char x;
	    unsigned char y;
	    unsigned char z;
	    unsigned char w;
	};

    /*--------------------------------------*\
     |*		int			*|
     \*-------------------------------------*/

    struct int2
	{
	    int x;
	    int y;
	};

    struct int3
	{
	    int x;
	    int y;
	    int z;
	};

    struct int4
	{
	    int x;
	    int y;
	    int z;
	    int w;
	};

    /*----------------------------------------------------------------------*\
     |*			Procedures 					    *|
     \*---------------------------------------------------------------------*/

    /*--------------------------------------*\
       |*		uchar			*|
     \*-------------------------------------*/

    static uchar4 make_uchar4(unsigned char x = 0, unsigned char y = 0, unsigned char z = 0, unsigned char w = 0)
	{
	uchar4 pixel;
	pixel.x = x;
	pixel.y = y;
	pixel.z = z;
	pixel.w = w;
	return pixel;
	}

    static uchar3 make_uchar3(unsigned char x = 0, unsigned char y = 0, unsigned char z = 0)
	{
	uchar3 pixel;
	pixel.x = x;
	pixel.y = y;
	pixel.z = z;
	return pixel;
	}

    static uchar2 make_uchar2(unsigned char x = 0, unsigned char y = 0)
	{
	uchar2 pixel;
	pixel.x = x;
	pixel.y = y;
	return pixel;
	}

    /*--------------------------------------*\
     |*		float			*|
     \*-------------------------------------*/

    static float4 make_float4(float x = 0, float y = 0, float z = 0, float w = 0)
	{
	float4 pixel;
	pixel.x = x;
	pixel.y = y;
	pixel.z = z;
	pixel.w = w;
	return pixel;
	}

    static float3 make_float3(float x = 0, float y = 0, float z = 0)
	{
	float3 pixel;
	pixel.x = x;
	pixel.y = y;
	pixel.z = z;
	return pixel;
	}

    static float2 make_float2(float x = 0, float y = 0)
	{
	float2 pixel;
	pixel.x = x;
	pixel.y = y;
	return pixel;
	}

    /*--------------------------------------*\
         |*		int			*|
     \*-------------------------------------*/

    static int4 make_int4(int x = 0, int y = 0, int z = 0, int w = 0)
	{
	int4 pixel;
	pixel.x = x;
	pixel.y = y;
	pixel.z = z;
	pixel.w = w;
	return pixel;
	}

    static int3 make_int3(int x = 0, int y = 0, int z = 0)
	{
	int3 pixel;
	pixel.x = x;
	pixel.y = y;
	pixel.z = z;
	return pixel;
	}

    static int2 make_int2(int x = 0, int y = 0)
	{
	int2 pixel;
	pixel.x = x;
	pixel.y = y;
	return pixel;
	}

    }

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
