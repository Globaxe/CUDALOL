#ifndef BOUNDOPERATION_H_
#define BOUNDOPERATION_H_

#include "envScene3dGL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr


#include "Transformation.h"
#include "Bound.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/


Bound transform(const Bound& bound,glm::mat4& matrix);

glm::mat4 computeCentrerRedui01Matrix(const Bound& bound);


#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
