#ifndef TRANSFORMATION_H_
#define TRANSFORMATION_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <glm/gtc/constants.hpp> //for constante
#include "envScene3dGL.h"
#include "Bound.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL Transformation
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Entity Transformation
	 */
	Transformation();

	Transformation(glm::vec3 position);

	Transformation(float angleRadian, glm::vec3& axis);

	Transformation(glm::mat3 rotationMat, glm::vec3 translation);

	Transformation(glm::mat4 matrix);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void mult(glm::mat4 matrix);

	void rotate(float angleRadian, glm::vec3 axis);

	void translate(glm::vec3 vector);

	void scale(glm::vec3 scaleXYZ);

	void rotate(float angleRadian, float x, float y, float z);

	/**
	 * glm::mat4 t = glm::translate(glm::mat4(), glm::vec3(x,yz)); //tranformation matrix
	 * glm::mat4 m; // model transformation
	 * m=m*t; // translation in local
	 */
	void translate(float x, float y, float z);

	void scale(float x, float y, float z);

	void scale(float scaleFactor);

	void centerReduce01(Bound& bound);

	/*--------------------------------------*\
	 |*		Parent			*|
	 \*-------------------------------------*/

	void multParent(glm::mat4 matrix);

	void rotateParent(float angleRadian, glm::vec3 axis);
	/**
	 * glm::mat4 t = glm::translate(glm::mat4(), glm::vec3(x,yz)); //tranformation matrix
	 * glm::mat4 m; // model transformation
	 * m = t * m; //translation global, ie don't care of the local rotations modifications
	 */
	void translateParent(glm::vec3 vector);

	void scaleParent(glm::vec3 scaleXYZ);

	void translateParent(float x, float y, float z);

	void scaleParent(float x, float y, float z);

	void rotateParent(float angleRadian, float x, float y, float z);


	void loadIdentity();

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setMatrix(glm::mat4 mat);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	float* getMatrixPoiner();

	glm::mat4 getMatrix() const;

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	glm::mat4 matrix;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
