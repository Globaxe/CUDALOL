#ifndef GL_SHADER_PROGRAM_H_
#define GL_SHADER_PROGRAM_H_

#include "Shader.h"
#include <vector>
using std::vector;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gl
    {
    /**
     * OpenGL Shader Program representation
     * OpenGL 2.0 -> 4.5
     * Official doc : https://www.opengl.org/sdk/docs/man4/
     * @author : joaquim.stahli@he-arc.ch
     */
    class CBI_GL ShaderProgram: public Object_A
	{
	    /*--------------------------------------*\
	     |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    ShaderProgram();

	    ShaderProgram(Shader* ptrVertexShader, Shader* ptrFragmentShader);

	    virtual ~ShaderProgram();

	    /*--------------------------------------*\
	     |*		Surcharge		*|
	     \*-------------------------------------*/

	protected:

	    virtual void initGL();

	    virtual void releaseGL();

	public:

	    virtual GLuint bind() const;

	    virtual void unBind() const;

	    /*--------------------------------------*\
	     |*		Methodes		*|
	     \*-------------------------------------*/

	public:

	    void attach(Shader* ptrShader);

	    void remove(Shader* ptrShader);

	private:

	    bool link();

	    /*--------------------------------------*\
	     |*		Get			*|
	     \*-------------------------------------*/

	public:

	    GLuint getUniformLocation(const char *name);

	    GLuint getAttribLocation(const char *name);

	    GLuint getSubroutineUniformLocation(GLenum shadertype, const char *name);

	    inline vector<Shader*> getTabAttachedShaders() const
		{
		return tabAttachedShaders;
		}

	    /*--------------------------------------*\
	     |*		Attributs		*|
	     \*-------------------------------------*/

	private:

	    vector<Shader*> tabAttachedShaders;

	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
