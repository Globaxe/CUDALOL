#ifndef SURFACE_STRIP_CPU_H_
#define SURFACE_STRIP_CPU_H_

#include "SurfaceStrip_A.h"
#include "MeshIndexed_CPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    typedef SurfaceStrip_A<float3, uchar3, RGB, GL_UNSIGNED_BYTE, DomainMath3D> SurfaceStrip_RGB_uchar3;
    typedef SurfaceStrip_A<float3, uchar4, RGBA, GL_UNSIGNED_BYTE, DomainMath3D> SurfaceStrip_RGBA_uchar4;

    typedef SurfaceStrip_A<float3,float3,RGB,GL_FLOAT,DomainMath3D> SurfaceStripRGB_float3;
    typedef SurfaceStrip_A<float3,float4,RGBA,GL_FLOAT,DomainMath3D> SurfaceStripRGBA_float4;

    typedef SurfaceStrip_A<float3,float,H,GL_FLOAT,DomainMath3D> SurfaceStrip_HUE_float;
    typedef SurfaceStrip_A<float3,float2,HA,GL_FLOAT,DomainMath3D> SurfaceStrip_HA_float2;
    typedef SurfaceStrip_A<float3, float3, HSB, GL_FLOAT, DomainMath3D> SurfaceStrip_HSB_float3;
    typedef SurfaceStrip_A<float3, float4, HSBA, GL_FLOAT, DomainMath3D> SurfaceStrip_HSBA_float4;
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
