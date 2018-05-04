#ifndef VECTORFIELD_CPU_H_
#define VECTORFIELD_CPU_H_

#include "cudaType_CPU.h"
#include "VectorField_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    typedef VectorField_A<float3,uchar4, ShapeColorModel::COLOR_MODEL_RGBA, ColorType::TYPE_UCHAR> VectorField_RGBA_uchar4;
    typedef VectorField_A<float3,uchar3, ShapeColorModel::COLOR_MODEL_RGB, ColorType::TYPE_UCHAR> VectorField_RGB_uchar3;

    typedef VectorField_A<float3,float4, ShapeColorModel::COLOR_MODEL_RGBA, ColorType::TYPE_FLOAT> VectorField_RGBA_float4;
    typedef VectorField_A<float3,float3, ShapeColorModel::COLOR_MODEL_RGB, ColorType::TYPE_FLOAT> VectorField_RGB_float3;
    typedef VectorField_A<float3,float4, ShapeColorModel::COLOR_MODEL_HSBA, ColorType::TYPE_FLOAT> VectorField_HSBA_float4;
    typedef VectorField_A<float3,float3, ShapeColorModel::COLOR_MODEL_HSB, ColorType::TYPE_FLOAT> VectorField_HSB_float3;
    typedef VectorField_A<float3,float2, ShapeColorModel::COLOR_MODEL_HA, ColorType::TYPE_FLOAT> VectorField_HA_float2;
    typedef VectorField_A<float3,float, ShapeColorModel::COLOR_MODEL_HUE, ColorType::TYPE_FLOAT> VectorField_HUE_float;
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
