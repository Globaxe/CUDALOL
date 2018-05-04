#ifndef NODE_INTERACTION_H_
#define NODE_INTERACTION_H_

#include "InputSetting.h"
#include "NodeInteraction_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL NodeInteraction: public NodeInteraction_A
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	NodeInteraction(Node_A* ptrPilotedNode = NULL, InputSetting inputSetting = InputSetting());

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	virtual void onMouseMoved(const MouseEvent& event);

	virtual void onMousePressed(const MouseEvent& event);

	virtual void onMouseReleased(const MouseEvent& event);

	virtual void onMouseWheel(const MouseWheelEvent& event);

	virtual void onKeyPressed(const KeyEvent& event);

	virtual void onKeyReleased(const KeyEvent& event);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public:

	InputSetting* getInputSettings();

	/*--------------------------------------*\
 |*		Is			*|
	 \*-------------------------------------*/

    public:

	inline bool isRotationEnable() const
	    {
	    return enableRotation;
	    }

	inline bool isTranslationEnable() const
	    {
	    return enableTranslation;
	    }

	inline bool isScaleEnable() const
	    {
	    return enableScale;
	    }

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/
    public:

	void setInputSettings(InputSetting inputSetting);

	void setRotationEnable(bool isEnable);
	void setTranslationEnable(bool isEnable);
	void setScaleEnable(bool isEnable);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	InputSetting inputSetting;

    protected:

	// Inputs state
	double oldX;
	double oldY;
	bool isButtonLeft;
	bool isButtonRight;
	bool isButtonMiddle;

	bool enableRotation;
	bool enableTranslation;
	bool enableScale;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
