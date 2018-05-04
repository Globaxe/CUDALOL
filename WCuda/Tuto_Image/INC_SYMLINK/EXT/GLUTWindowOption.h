#ifndef GLUTWINDOW_OPTION_H_
#define GLUTWINDOW_OPTION_H_

#include "envFreeGlutTools.h"
#include "GLConfig.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * GLUT 3
 * 	https://www.opengl.org/resources/libraries/glut/spec3
 *
 * Freeglut
 *
 * 	http://freeglut.sourceforge.net/docs/api.ph
 */
class CBI_FREEGLUT_TOOLS GLUTWindowOption
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * displayMode :
	 * 	GLUT_RGBA
	 * 	GLUT_RGB
	 * 	GLUT_INDEX
	 * 	GLUT_SINGLE
	 * 	GLUT_DOUBLE
	 * 	GLUT_ACCUM
	 * 	GLUT_ALPHA
	 * 	GLUT_DEPTH
	 * 	GLUT_STENCIL
	 * 	GLUT_MULTISAMPLE
	 * 	GLUT_STEREO
	 * 	GLUT_LUMINANCE
	 * 	GLUT_AUX
	 *
	 * actionOnClose :
	 * 	GLUT_ACTION_EXIT
	 * 	GLUT_ACTION_GLUTMAINLOOP_RETURNS
	 * 	GLUT_ACTION_CONTINUE_EXECUTION
	 *
	 *  renderingContext :
	 * 	GLUT_CREATE_NEW_CONTEXT
	 * 	GLUT_USE_CURRENT_CONTEXT
	 */
	GLUTWindowOption(int displayMode, int actionOnClose, int renderingContext, int auxBufferCount, int multisampleCount);

	/**
	 * displayMode :
	 * 	GLUT_RGBA
	 * 	GLUT_RGB
	 * 	GLUT_INDEX
	 * 	GLUT_SINGLE
	 * 	GLUT_DOUBLE
	 * 	GLUT_ACCUM
	 * 	GLUT_ALPHA
	 * 	GLUT_DEPTH
	 * 	GLUT_STENCIL
	 * 	GLUT_MULTISAMPLE
	 * 	GLUT_STEREO
	 * 	GLUT_LUMINANCE
	 * 	GLUT_AUX
	 *
	 * actionOnClose :
	 * 	GLUT_ACTION_EXIT
	 * 	GLUT_ACTION_GLUTMAINLOOP_RETURNS
	 * 	GLUT_ACTION_CONTINUE_EXECUTION
	 *
	 *  renderingContext :
	 * 	GLUT_CREATE_NEW_CONTEXT		1 context per Window
	 * 	GLUT_USE_CURRENT_CONTEXT	1 context for all Windows ("for all windows created with GLUT_USE_CURRENT_CONTEXT", the current context is use, freeglut is smart if there is no context created)
	 */
	GLUTWindowOption(int displayMode, int actionOnClose = GLUT_ACTION_EXIT, int renderingContext = GLUT_CREATE_NEW_CONTEXT);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline int getDisplayMode() const
	    {
	    return displayMode;
	    }

	inline int getActionOnClose() const
	    {
	    return actionOnClose;
	    }

	inline int getRenderingContext() const
	    {
	    return renderingContext;
	    }

	inline int getAuxBufferCount() const
	    {
	    return auxBufferCount;
	    }

	inline int getMultiSampleCount() const
	    {
	    return multisampleCount;
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	/**
	 * GLUT possible bitmask value are :
	 * 	GLUT_RGBA
	 * 	GLUT_RGB
	 * 	GLUT_INDEX
	 * 	GLUT_SINGLE
	 * 	GLUT_DOUBLE
	 * 	GLUT_ACCUM
	 * 	GLUT_ALPHA
	 * 	GLUT_DEPTH
	 * 	GLUT_STENCIL
	 * 	GLUT_MULTISAMPLE
	 * 	GLUT_STEREO
	 * 	GLUT_LUMINANCE
	 * 	GLUT_AUX
	 *
	 * Sample :
	 *
	 * 	GLUT_RGBA | GLUT_DEPTH
	 *
	 * More infos :
	 * 	https://www.opengl.org/resources/libraries/glut/spec3/node12.html#SECTION00033000000000000000
	 */
	int displayMode;

	/**
	 * GLUT possible variables are :
	 * 	GLUT_ACTION_EXIT
	 * 	GLUT_ACTION_GLUTMAINLOOP_RETURNS
	 * 	GLUT_ACTION_CONTINUE_EXECUTION
	 */
	int actionOnClose;

	/**
	 * GLUT possible variables are :
	 * 	GLUT_CREATE_NEW_CONTEXT
	 * 	GLUT_USE_CURRENT_CONTEXT
	 */
	int renderingContext;

	/**
	 * Number of Aux buffer, if enable in displayMode (GLUT_AUX)
	 */
	int auxBufferCount;

	/**
	 * Number of samples, if enable in displayMode (GLUT_MULTISAMPLE)
	 */
	int multisampleCount;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
