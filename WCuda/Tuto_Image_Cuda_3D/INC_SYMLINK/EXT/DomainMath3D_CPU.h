#ifndef DOMAINMATH3D_CPU_H_
#define DOMAINMATH3D_CPU_H_

#include "envGLSurface.h"
#include "cudaType_CPU.h"
#include "Bound.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    class CBI_SURFACE_GL DomainMath3D
	{
	    /*--------------------------------------*\
	   	 |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    DomainMath3D(const Bound& bound);

	    DomainMath3D(float x_min, float x_max, float y_min, float y_max, float z_min, float z_max);

	    /*--------------------------------------*\
	   	 |*		Methodes		*|
	     \*-------------------------------------*/

	public:

	    DomainMath3D& operator=(const Bound& bound);

	    Bound toBound() const;

	    DomainMath3D transform(const float3& translation, const float3& scales);

	    void translate(const float3& t);

	    void scale(const float3& scales);

	    inline float deltaX() const
		{
		return fabs(x_max - x_min);
		}

	    inline float deltaY() const
		{
		return fabs(y_max - y_min);
		}

	    inline float deltaZ() const
		{
		return fabs(z_max - z_min);
		}

	    inline float3 deltaXYZ() const
		{
		return make_float3(deltaX(), deltaY(), deltaZ());
		}

	    float3 gravity() const;

	    /**
	     * Usefull for SurfaceStrip (HightMap)
	     */
	    void delta(const int& w, const int& h, float* ptrDx, float* ptrDy) const;

	    /**
	     * Usefull for SurfaceStrip (HightMap)
	     */
	    void toXY(const float& dx, const float& dy, const int& vertexI, const int& vertexJ, float* ptrX, float* ptrY) const;

	    /*--------------------------------------*\
	    |*		Is			*|
	     \*-------------------------------------*/

	    /**
	     * true if b is in a
	     */
	    static bool isDomaineInscrit(const DomainMath3D& a, const DomainMath3D& b);

	    /*--------------------------------------*\
	   	 |*		Friend			*|
	     \*-------------------------------------*/

	    friend ostream& operator<<(ostream& stream, const cpu::DomainMath3D& domaine);

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
