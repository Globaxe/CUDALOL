#ifndef INDEXED_MESH_CPU_H_
#define INDEXED_MESH_CPU_H_

#include "MeshIndexed_A.h"
#include "Mesh_CPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    typedef MeshIndexed_A<float3, uchar3, RGB, GL_UNSIGNED_BYTE, DomainMath3D> MeshIndexed_RGB_uchar3;
    typedef MeshIndexed_A<float3, uchar4, RGBA, GL_UNSIGNED_BYTE, DomainMath3D> MeshIndexed_RGBA_uchar4;
    typedef MeshIndexed_A<float3,float3,RGB,GL_FLOAT,DomainMath3D> MeshIndexedRGB_float3;
    typedef MeshIndexed_A<float3,float4,RGBA,GL_FLOAT,DomainMath3D> MeshIndexedRGBA_float4;

    typedef MeshIndexed_A<float3,float,H,GL_FLOAT,DomainMath3D> MeshIndexed_HUE_float;
    typedef MeshIndexed_A<float3,float2,HA,GL_FLOAT,DomainMath3D> MeshIndexed_HA_float2;
    typedef MeshIndexed_A<float3, float3, HSB, GL_FLOAT, DomainMath3D> MeshIndexed_HSB_float3;
    typedef MeshIndexed_A<float3, float4, HSBA, GL_FLOAT, DomainMath3D> MeshIndexed_HSBA_float4;
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
