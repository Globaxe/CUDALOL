#ifndef GROUP_NODE_H_
#define GROUP_NODE_H_

#include <vector>
#include "Node_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL GroupNode: public Node_A
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	GroupNode(string name, Transformation transformation = Transformation());

	virtual ~GroupNode();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/
    public:

	virtual void draw();

	virtual void init();

	virtual void release();

	virtual void animationStep();

	virtual Bound getBound() const;

	virtual Bound getBoundTransformed() const;

	virtual void paintPrimitives(Graphic2D& ptrGraphic2D);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/


    public:

	bool add(Node_A* child);

	bool addFirst(Node_A* child);

	bool removeChild(Node_A* child);

	bool removeChildByName(string nodeName);

	bool removeChildById(long id);

	Node_A* findChildByName(string name) const;

	Node_A* findChildById(long id) const;

    private:

	void computeBoundFromChildren();

	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public :

	unsigned int getChildrenCount() const;

	/**
	 * Superficial copy of vectorChild
	 */
	std::vector<Node_A*> getChildren() const;

	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public:

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Tools
	std::vector<Node_A*> vectorChild;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
