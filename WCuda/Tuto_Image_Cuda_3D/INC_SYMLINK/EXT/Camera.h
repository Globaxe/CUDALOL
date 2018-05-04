#ifndef CAMERA_H_
#define CAMERA_H_

#include "envScene3dGL.h"
#include "Transformation.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Store the View transformation and the projection transformation
 */
class CBI_SCENE3D_GL Camera
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Default camera
	 */
	Camera();

	Camera(glm::vec3 eye, glm::vec3 center, glm::vec3 axe, glm::mat4 projectionMatrix);

	/**
	 * Generic projection camera
	 */
	Camera(Transformation viewTransformation, glm::mat4 projectionMatrix);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

	virtual ~Camera()
	    {
	    // Nothing
	    }

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

	inline Transformation* getViewTransformation()
	    {
	    return &viewTransformation;
	    }

	inline glm::mat4 getProjectionMatrix() const
	    {
	    return projectionMatrix;
	    }

	inline glm::vec3 getEye() const
	    {
	    return eye;
	    }

	inline glm::vec3 getCenter() const
	    {
	    return center;
	    }

	inline glm::vec3 getAxe() const
	    {
	    return axe;
	    }

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setProjectionMatrix(glm::mat4 projectionMatrix);

	void setViewTransformation(Transformation& viewTransformation);

	void setCenter(float x, float y, float z);

	void setEye(float x, float y, float z);

	void setAxe(float x, float y, float z);

    private:

	void updateViewMatrix();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    protected:
	// Inputs
	glm::vec3 eye; // Position de la caméra
	glm::vec3 center; //Point visée, caméra regarde dans la direction eye-center
	glm::vec3 axe; // Vecteur permettant de faire tourner la caméra sur elle-meme, caméra standart a plate donnée par (0,1,0)

	// Tools
	Transformation viewTransformation;
	glm::mat4 projectionMatrix;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
