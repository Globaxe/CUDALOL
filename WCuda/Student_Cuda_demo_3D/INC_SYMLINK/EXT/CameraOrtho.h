#ifndef CAMERA_ORTHO_H_
#define CAMERA_ORTHO_H_

#include "Camera.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL CameraOrtho: public Camera
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	CameraOrtho();

	CameraOrtho(glm::vec3 eye, glm::vec3 center, glm::vec3 axe, float left, float right, float bottom, float top, float near, float far);

	virtual ~CameraOrtho();

	/*--------------------------------------*\
 |*		Methodes		*|
	 \*-------------------------------------*/

    private:

	void updateProjectionMatrix();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline float getLeft() const
	    {
	    return left;
	    }

	inline float getRight() const
	    {
	    return right;
	    }

	inline float getBottom() const
	    {
	    return bottom;
	    }

	inline float getTop() const
	    {
	    return top;
	    }

	inline float getNear() const
	    {
	    return near;
	    }
	inline float getFar() const
	    {
	    return far;
	    }

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void set(float left, float right, float bottom, float top, float near, float far);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Inputs
	float left;
	float right;
	float bottom;
	float top;
	float near;
	float far;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
