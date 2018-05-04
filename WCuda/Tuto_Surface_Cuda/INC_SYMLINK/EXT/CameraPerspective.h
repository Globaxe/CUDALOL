#ifndef CAMERA_PERSPECTIVE_H_
#define CAMERA_PERSPECTIVE_H_

#include "Camera.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL CameraPerspective: public Camera
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	CameraPerspective(glm::vec3 eye, glm::vec3 center, glm::vec3 axe, float fovy, float ratio, float nearPlane, float farPlane);

	virtual ~CameraPerspective();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    private:

	void updateProjectionMatrix();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline float getFovy() const
	    {
	    return fovy;
	    }

	inline float getRatio() const
	    {
	    return ratio;
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

	void setFovy(float fovy);

	void setRatio(float ratio);

	void setNear(float near);

	void setFar(float far);

	void setNearFar(float near, float far);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	float fovy;
	float ratio;
	float near;
	float far;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
