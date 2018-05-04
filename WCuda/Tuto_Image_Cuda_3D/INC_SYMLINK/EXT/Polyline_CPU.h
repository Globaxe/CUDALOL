#ifndef POLYLINE_CPU_H_
#define POLYLINE_CPU_H_

#include "cudaType_CPU.h"
#include "Polyline_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    typedef Polyline_A<float3,uchar4, ShapeColorModel::COLOR_MODEL_RGBA, ColorType::TYPE_UCHAR> Polyline_RGBA_uchar4;
    typedef Polyline_A<float3,uchar3, ShapeColorModel::COLOR_MODEL_RGB, ColorType::TYPE_UCHAR> Polyline_RGB_uchar3;

    typedef Polyline_A<float3,float4, ShapeColorModel::COLOR_MODEL_RGBA, ColorType::TYPE_FLOAT> Polyline_RGBA_float4;
    typedef Polyline_A<float3,float3, ShapeColorModel::COLOR_MODEL_RGB, ColorType::TYPE_FLOAT> Polyline_RGB_float3;
    typedef Polyline_A<float3,float4, ShapeColorModel::COLOR_MODEL_HSBA, ColorType::TYPE_FLOAT> Polyline_HSBA_float4;
    typedef Polyline_A<float3,float3, ShapeColorModel::COLOR_MODEL_HSB, ColorType::TYPE_FLOAT> Polyline_HSB_float3;
    typedef Polyline_A<float3,float2, ShapeColorModel::COLOR_MODEL_HA, ColorType::TYPE_FLOAT> Polyline_HA_float2;
    typedef Polyline_A<float3,float, ShapeColorModel::COLOR_MODEL_HUE, ColorType::TYPE_FLOAT> Polyline_HUE_float;
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
