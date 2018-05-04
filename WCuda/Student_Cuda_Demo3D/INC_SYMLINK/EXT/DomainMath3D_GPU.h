#ifndef DOMAINMATH_3D_GPU_H_
#define DOMAINMATH_3D_GPU_H_

#include "envGLSurfaceCudas.h"
#include "cudaObject.h" //for __BOTH__
#include <math.h>
#include <iostream>
#include "Bound.h"

using std::ostream;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/
namespace gpu
    {
class CBI_SURFACE_GL_CUDA DomainMath3D
    {

    /*--------------------------------------*\
	 |*		Constructor		*|
     \*-------------------------------------*/

    public:

    DomainMath3D(const Bound& bound) :
    x_min(bound.x_min), x_max(bound.x_max), y_min(bound.y_min), y_max(bound.y_max), z_min(bound.z_min), z_max(bound.z_max)
	{

	}

    __BOTH__
    DomainMath3D(float x_min, float x_max, float y_min, float y_max, float z_min, float z_max) :
    x_min(x_min), x_max(x_max), y_min(y_min), y_max(y_max), z_min(z_min), z_max(z_max)
	{

	}

    /*--------------------------------------*\
	 |*		Methodes		*|
     \*-------------------------------------*/

    public:

    /*--------------*\
	    |*	Host	*|
     \*-------------*/

    DomainMath3D& operator=(const Bound& bound);

    Bound toBound() const;

    /*--------------*\
	     |*	BOTH	*|
     \*-------------*/

    __BOTH__
    DomainMath3D transform(const float3& translation, const float3& scales)
	{
	DomainMath3D domainTransform(*this);
	domainTransform.translate(translation);
	domainTransform.scale(scales);
	return domainTransform;
	}

    __BOTH__
    void translate(const float3& t)
	{
	x_min += t.x;
	x_max += t.x;
	y_min += t.y;
	y_max += t.y;
	z_min += t.z;
	z_max += t.z;
	}

    __BOTH__
    void scale(const float3& scales)
	{
	float3 g = gravity();
	// computeNewSize
	float dx2 = deltaX() * scales.x / 2;
	float dy2 = deltaY() * scales.y / 2;
	float dz2 = deltaZ() * scales.z / 2;

	x_min = g.x - dx2;
	x_max = g.x + dx2;

	y_min = g.y - dy2;
	y_max = g.y + dy2;

	z_min = g.z - dz2;
	z_max = g.z + dz2;
	}

    __BOTH__
    float deltaX() const
	{
	return fabs(x_max - x_min);
	}

    __BOTH__
    float deltaY() const
	{
	return fabs(y_max - y_min);
	}

    __BOTH__
    float deltaZ() const
	{
	return fabs(z_max - z_min);
	}

    __BOTH__
    float3 deltaXYZ() const
	{
	return make_float3(deltaX(), deltaY(), deltaZ());
	}

    __BOTH__
    float3 gravity() const
	{
	return make_float3(x_min + (deltaX() / 2.0f), y_min + (deltaY() / 2.0f), z_min + (deltaZ() / 2.0f));
	}

    /**
     * Usefull for SurfaceStrip (HightMap)
     */
    __BOTH__
    void delta(const int& w, const int& h,float* ptrDx,float* ptrDy) const
	{
	*ptrDx = deltaX() / (w - 1);
	*ptrDy = deltaY() / (h - 1);
	}

    /**
     * Usefull for SurfaceStrip (HightMap)
     */
    __BOTH__
    void toXY(const float& dx,const float& dy,const int& vertexI,const int& vertexJ,float* ptrX,float* ptrY) const
	{
	*ptrX = x_min + vertexJ * dx;
	*ptrY = y_min + vertexI * dy;
	}

    /*--------------------------------------*\
 |*		Is			*|
     \*-------------------------------------*/

    /**
     * true if b is in a
     */
    __BOTH__
    static bool isDomaineInscrit(const DomainMath3D& a, const DomainMath3D& b)
	{
	return b.x_min >= a.x_min && b.x_max <= a.x_max && b.y_min >= a.y_min && b.y_max <= a.y_max && b.z_min >= a.z_min && b.z_max <= a.z_max;
	}

    /*--------------------------------------*\
	 |*		Friend			*|
     \*-------------------------------------*/

    friend ostream& operator<<(ostream& stream, const gpu::DomainMath3D& domaine);

    /*--------------------------------------*\
	 |*		Attributs		*|
     \*-------------------------------------*/

    public:

    // Inputs
    float x_min;
    float x_max;
    float y_min;
    float y_max;
    float z_min;
    float z_max;

    };
}

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
