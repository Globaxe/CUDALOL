#ifndef NODE_A_H_
#define NODE_A_H_
#include "Bound.h"
#include "Graphic2D.h"
#include "Transformation.h"

#include <chrono>
#include <string>
#include "envScene3dGL.h"

class GroupNode;
//because we can't include GroupNode.h here

using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL Node_A
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Node_A(string name, Transformation transformation);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

	virtual ~Node_A();

    public:

	virtual void draw()=0;

	virtual void init()=0;

	virtual void release()=0;

	virtual void animationStep();

	virtual void paintPrimitives(Graphic2D& ptrGraphic2D);

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setParent(GroupNode* ptrParent);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	virtual Bound getBoundTransformed() const=0;

	virtual Bound getBound() const=0;

	inline string getName() const
	    {
	    return name;
	    }

	inline long getId() const
	    {
	    return id;
	    }

	inline Transformation* getTransformation()
	    {
	    return &transformation;
	    }

	inline GroupNode* getParent() const
	    {
	    return ptrParent;
	    }

	/*--------------------------------------*\
	 |*		Is			*|
	 \*-------------------------------------*/

    public:

	bool isOrphan() const;

	/*--------------------------------------*\
	 |*		Delegates		*|
	 \*-------------------------------------*/

    public:

	void mult(glm::mat4 matrix);

	void rotate(float angle, glm::vec3 axis);

	void translate(glm::vec3 vector);

	void scale(glm::vec3 scaleXYZ);

	void rotate(float angle, float x, float y, float z);

	/**
	 * glm::mat4 t = glm::translate(glm::mat4(), glm::vec3(x,yz)); //tranformation matrix
	 * glm::mat4 m; // model transformation
	 * m=m*t; // translation in local
	 */
	void translate(float x, float y, float z);

	void scale(float x, float y, float z);

	void scale(float scaleFactor);

	void multParent(glm::mat4 matrix);

	void rotateParent(float angle, glm::vec3 axis);

	/**
	 * glm::mat4 t = glm::translate(glm::mat4(), glm::vec3(x,yz)); //tranformation matrix
	 * glm::mat4 m; // model transformation
	 * m = t * m; //translation global, ie don't care of the local rotations modifications
	 */
	void translateParent(glm::vec3 vector);

	void scaleParent(glm::vec3 scaleXYZ);

	void loadIdentity();

	void centerReduce01();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    protected:
	// Inputs
	GroupNode* ptrParent;
	Transformation transformation;

    private:
	// Inputs
	string name;
	long id;

    };

// Ciclyc depandancy, include has to be done here
#include "GroupNode.h"

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
