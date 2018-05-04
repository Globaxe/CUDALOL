#ifndef CORE_HEADER_GL_BOUND_H_
#define CORE_HEADER_GL_BOUND_H_

#include <math.h>
#include <iostream>
#include <glm/glm.hpp>
#include "envScene3dGL.h"

using std::ostream;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL Bound
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Bound(float x_min = 0, float x_max = 0, float y_min = 0, float y_max = 0, float z_min = 0, float z_max = 0);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	Bound transform(glm::mat4& matrix) const;

//	Bound transform(float tx, float ty, float tz, float scaleX, float scaleY, float scaleZ);

	void translate(float x, float y, float z);

	void scale(float scaleX, float scaleY, float scaleZ);

	float deltaX() const;

	float deltaY() const;

	float deltaZ() const;

	void gravity(float tabGravityXYZ[3]) const;


	glm::vec3 gravity() const;

	static Bound computeBound(float* ptrTabVertices, int vertexCount);

	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public:

	void getSpacePoint(glm::vec3 tabPoint[8]) const;

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

	/**
	 * Combine two bounds
	 */
	Bound &operator+=(const Bound &b);

	Bound operator+(const Bound &b);

	/*--------------------------------------*\
	 |*		Is			*|
	 \*-------------------------------------*/

	/**
	 * true if b is in a
	 */
	static bool isInscrit(const Bound& a, const Bound& b);

	/*--------------------------------------*\
	|*		Friend			*|
	 \*-------------------------------------*/



	friend ostream& operator<<(ostream& stream, const Bound& domaine);

    public:

	// Inputs
	float x_min;
	float x_max;
	float y_min;
	float y_max;
	float z_min;
	float z_max;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
