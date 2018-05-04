#ifndef GL_OBJECT_A_H_
#define GL_OBJECT_A_H_

#include "envBilatGL.h"
#include <GL/glew.h>
#include <atomic>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gl
    {
    /**
     * Official doc : https://www.opengl.org/sdk/docs/man4/
     * @author : joaquim.stahli@he-arc.ch
     */
    class CBI_GL Object_A
	{
	    /*--------------------------------------*\
	 |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    Object_A();

	private:

	    Object_A(const Object_A& src)
		{
		// Copie interdit => atomic<int>
		}

	public:
	    /**
	     * Affectation operator doesn't modifiate the instance!
	     * No copy is allowed!
	     */
	    virtual Object_A& operator=(const Object_A& src)
		{
		// Affectation interdit =>  atomic<int>
		return (*this);
		}

	    /*--------------------------------------*\
	 |*		Destructor		*|
	     \*-------------------------------------*/

	public:

	    virtual ~Object_A();

	    /*--------------------------------------*\
	     |*		Methodes		*|
	     \*-------------------------------------*/

	protected:

	    virtual void initGL()=0;

	    virtual void releaseGL()=0;

	public:

	    virtual GLuint bind() const=0;

	    virtual void unBind() const;

	    bool init();

	    bool release();

	    /*--------------------------------------*\
	 |*		Get			*|
	     \*-------------------------------------*/

	public:

	    inline GLuint getId() const
		{
		return id[0];
		}

	    /*--------------------------------------*\
	 |*		Is			*|
	     \*-------------------------------------*/

	public:

	    bool isInit() const;

	    /*--------------------------------------*\
	 |*		Attributs		*|
	     \*-------------------------------------*/

	protected:
	    GLuint id[1];

	private:

	    std::atomic<int> initCount;
	};
    }
#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
