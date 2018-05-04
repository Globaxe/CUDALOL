#ifndef	BRAIN_CPU_H_
#define BRAIN_CPU_H_

#include "MeshIndexed_CPU.h"
#include "Brain_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    typedef Brain_A<float3, uchar3, RGB, GL_UNSIGNED_BYTE, DomainMath3D> Brain_RGB_uchar3;
    typedef Brain_A<float3, uchar4, RGBA, GL_UNSIGNED_BYTE, DomainMath3D> Brain_RGBA_uchar4; // Default type

    typedef Brain_A<float3, float, H, GL_FLOAT, DomainMath3D> Brain_HUE_float;
    typedef Brain_A<float3, float2, HA, GL_FLOAT, DomainMath3D> Brain_HA_float2;
    typedef Brain_A<float3, float3, HSB, GL_FLOAT, DomainMath3D> Brain_HSB_float3;
    typedef Brain_A<float3, float4, HSBA, GL_FLOAT, DomainMath3D> Brain_HSBA_float4;
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
