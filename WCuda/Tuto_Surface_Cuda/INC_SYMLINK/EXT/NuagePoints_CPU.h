#ifndef NUAGEPOINTS_CPU_H_
#define NUAGEPOINTS_CPU_H_

#include "cudaType_CPU.h"
#include "NuagePoints_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    typedef NuagePoints_A<float3,uchar4, ShapeColorModel::COLOR_MODEL_RGBA, ColorType::TYPE_UCHAR> NuagePoints_RGBA_uchar4;
    typedef NuagePoints_A<float3,uchar3, ShapeColorModel::COLOR_MODEL_RGB, ColorType::TYPE_UCHAR> NuagePoints_RGB_uchar3;

    typedef NuagePoints_A<float3,float4, ShapeColorModel::COLOR_MODEL_RGBA, ColorType::TYPE_FLOAT> NuagePoints_RGBA_float4;
    typedef NuagePoints_A<float3,float3, ShapeColorModel::COLOR_MODEL_RGB, ColorType::TYPE_FLOAT> NuagePoints_RGB_float3;
    typedef NuagePoints_A<float3,float4, ShapeColorModel::COLOR_MODEL_HSBA, ColorType::TYPE_FLOAT> NuagePoints_HSBA_float4;
    typedef NuagePoints_A<float3,float3, ShapeColorModel::COLOR_MODEL_HSB, ColorType::TYPE_FLOAT> NuagePoints_HSB_float3;
    typedef NuagePoints_A<float3,float2, ShapeColorModel::COLOR_MODEL_HA, ColorType::TYPE_FLOAT> NuagePoints_HA_float2;
    typedef NuagePoints_A<float3,float, ShapeColorModel::COLOR_MODEL_HUE, ColorType::TYPE_FLOAT> NuagePoints_HUE_float;
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
