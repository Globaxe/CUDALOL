#ifndef MESH_CPU_H_
#define MESH_CPU_H_

#include <GL/glew.h>
#include "Mesh_A.h"

//for float3, uchar4
#include "cudaType_CPU.h"
#include "DomainMath3D_CPU.h"



/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    typedef Mesh_A<float3,uchar3,RGB,GL_UNSIGNED_BYTE,DomainMath3D> Mesh_RGB_uchar3;
    typedef Mesh_A<float3,uchar4,RGBA,GL_UNSIGNED_BYTE,DomainMath3D> Mesh_RGBA_uchar4;
    typedef Mesh_A<float3,float3,RGB,GL_FLOAT,DomainMath3D> Mesh_RGB_float3;
    typedef Mesh_A<float3,float4,RGBA,GL_FLOAT,DomainMath3D> Mesh_RGBA_float4;


    typedef Mesh_A<float3,float,H,GL_FLOAT,DomainMath3D> Mesh_HUE_float;
    typedef Mesh_A<float3,float2,HA,GL_FLOAT,DomainMath3D> Mesh_HA_float2;
    typedef Mesh_A<float3,float3,HSB,GL_FLOAT,DomainMath3D> Mesh_HSB_float3;
    typedef Mesh_A<float3,float4,HSBA,GL_FLOAT,DomainMath3D> Mesh_HSBA_float4;
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
