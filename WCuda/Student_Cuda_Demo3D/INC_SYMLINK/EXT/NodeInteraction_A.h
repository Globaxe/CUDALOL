#ifndef NODE_INTERACTION_A_H_
#define NODE_INTERACTION_A_H_

#include "MouseListener_I.h"
#include "KeyListener_I.h"
#include "Node_A.h"
#include "Graphic2D.h"
#include <stdlib.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL NodeInteraction_A : public MouseListener_I, public KeyListener_I
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	NodeInteraction_A(Node_A* ptrPilotedNode = NULL);

	virtual ~NodeInteraction_A();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Call bye the Scene
	 */
	virtual void drawPrimitives(Graphic2D& graphic2D);

	void reset();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline Node_A* getNodeToInteract()
	    {
	    return ptrNodeToInteract;
	    }

	inline bool hasNode() const
	    {
	    return ptrNodeToInteract == NULL;
	    }

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setNodeToInteract(Node_A* ptrGraphNodeToPilote);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    protected:
	// Inputs
	Node_A* ptrNodeToInteract;

	// Tools
	glm::mat4 intialTransformation;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
