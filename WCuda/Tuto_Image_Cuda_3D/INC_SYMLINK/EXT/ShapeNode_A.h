#ifndef SHAPE_NODE_A_H_
#define SHAPE_NODE_A_H_

#include "Node_A.h"
#include "ShapeAppearance.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL ShapeNode_A: public Node_A
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ShapeNode_A(string name, Transformation transformation = Transformation(), ShapeAppearance appearance = ShapeAppearance());

	virtual ~ShapeNode_A();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	virtual void draw();

	virtual void drawGeometry()=0;

	virtual void init();

	virtual void release();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    protected:

	virtual void startDrawing();

	virtual void stopDrawing();

	virtual void drawAppearance();

	virtual void boundChanged();

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

	static void pushGLState();

	static void popGLState();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline ShapeAppearance* getAppearance()
	    {
	    return &appearance;
	    }

	virtual Bound getBound() const;

	virtual Bound getBoundTransformed() const;

	/*--------------------------------------*\
 |*		Is			*|
	 \*-------------------------------------*/

    public:

	inline bool isInit()
	    {
	    return isShapeInit;
	    }

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:
	void setBound(const Bound& bound);

	void setAppearance(const ShapeAppearance& appearance);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    protected:
	//Inputs
	Bound bound;
	ShapeAppearance appearance;
	bool isShapeInit;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
