#ifndef QUADRIC_H_
#define QUADRIC_H_

#include <GL/glew.h>
#include <GL/glu.h>

#include "envScene3dGL.h"
#include "Bound.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Quadric are depreciated in most recent OpenGL version.
 */
class CBI_SCENE3D_GL Quadric
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Quadric();

	Quadric(const Quadric& src);

	virtual ~Quadric();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

	  virtual Quadric& operator=(const Quadric& src);

	  /*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public :

	  virtual void drawQuadric()=0;

	  /*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public :

	  Bound getBound() const;

	  /*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    protected:

	  // Output
	GLUquadricObj* ptrGLUquadricObj;
	Bound bound;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
