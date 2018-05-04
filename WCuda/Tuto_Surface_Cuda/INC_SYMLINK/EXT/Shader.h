#ifndef GL_SHADER_H_
#define GL_SHADER_H_

#include "Object_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gl
    {
    /**
     * Utility struct that store data for ShaderCode
     */
    struct ShaderCode
	{
	    int count;
	    const char** string;
	    int* length;
	};

    /**
     * OpenGL Shader representation, like Vertex, Fragment or even Geometry shader.
     * Remember with recent OpenGL specification, you need to use shader!
     * OpenGL 2.0 -> 4.5
     * Official doc : https://www.opengl.org/sdk/docs/man4/
     * @author : joaquim.stahli@he-arc.ch
     */
    class CBI_GL Shader: public Object_A
	{
	    /*--------------------------------------*\
	 |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    /**
	     * @param shaderType GL_VERTEX_SHADER or GL_FRAGMENT_SHADER
	     */
	    Shader(GLenum shaderType, int count, const char** string, int* length);

	    /**
	     * @param shaderType GL_VERTEX_SHADER or GL_FRAGMENT_SHADER
	     */
	    Shader(GLenum shaderType, const char** string);

	    /**
	     * @param shaderType GL_VERTEX_SHADER or GL_FRAGMENT_SHADER
	     */
	    Shader(GLenum shaderType, ShaderCode& shaderCode);

	    /*--------------------------------------*\
	 |*		Methodes		*|
	     \*-------------------------------------*/

	protected:

	    virtual void initGL();

	    virtual void releaseGL();

	public:

	    virtual GLuint bind() const;

	    virtual void unBind() const;

	private:

	    /**
	     * @param count Specifies the number of elements in the string and length arrays.
	     * @param Specifies an array of pointers to strings containing the source code to be loaded into the shader.
	     * @param lenght Specifies an array of string lengths.
	     * @return true if compile success without compilationError
	     */
	    bool compile(int count, const char** string, int* length);

	    /*--------------------------------------*\
	 |*		Attributs		*|
	     \*-------------------------------------*/

	private:

	    GLenum shaderType;
	    ShaderCode shaderCode;

	};

    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
