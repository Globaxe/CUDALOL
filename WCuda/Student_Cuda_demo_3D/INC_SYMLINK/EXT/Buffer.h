#ifndef GL_BUFFER_H_
#define GL_BUFFER_H_

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
     * OpenGL buffer representation like VertexBufferObject or PixelBufferObject
     * OpenGL 2.0 -> 4.5
     */
    class CBI_GL Buffer: public Object_A
	{

	    /*--------------------------------------*\
	     |*		Constructor		    *|
	     \*-------------------------------------*/
	public:

	    /**
	     * See official documentation for more target possibilities depending of the OpenGL version you want to use.
	     *
	     * @param target OpenGL 2.0 (GL_ARRAY_BUFFER, GL_ELEMENT_ARRAY_BUFFER, GL_PIXEL_PACK_BUFFER, or GL_PIXEL_UNPACK_BUFFER)
	     */
	    Buffer(GLenum target);

	    /*--------------------------------------*\
	     |*		Destructor		*|
	     \*-------------------------------------*/

	public:

	    virtual ~Buffer();

	    /*--------------------------------------*\
	     |*		Methodes		*|
	     \*-------------------------------------*/

	protected:

	    virtual void initGL();

	    virtual void releaseGL();

	public:

	    /*
	     *  @param bufferUsage
	     *  	GL_STREAM_DRAW
	     *  	GL_STREAM_READ
	     *  	GL_STREAM_COPY
	     *  	GL_STATIC_DRAW
	     *  	GL_STATIC_READ
	     *  	GL_STATIC_COPY
	     *  	GL_DYNAMIC_DRAW
	     *  	GL_DYNAMIC_READ
	     *  	GL_DYNAMIC_COPY)
	     */
	    virtual void bufferData(unsigned int sizeOctet, GLenum bufferUsage = GL_STREAM_DRAW);

	    /*
	     *  @param bufferUsage
	     *  	GL_STREAM_DRAW
	     *  	GL_STREAM_READ
	     *  	GL_STREAM_COPY
	     *  	GL_STATIC_DRAW
	     *  	GL_STATIC_READ
	     *  	GL_STATIC_COPY
	     *  	GL_DYNAMIC_DRAW
	     *  	GL_DYNAMIC_READ
	     *  	GL_DYNAMIC_COPY)
	     */
	    virtual void bufferData(unsigned int sizeOctet, void* bufferData, GLenum bufferUsage);

	    virtual void bufferSubData(unsigned int offset, unsigned int sizeOctet, void* bufferData);

	    /**
	     * @param access
	     * 	GL_READ_ONLY
	     * 	GL_WRITE_ONLY
	     * 	GL_READ_WRITE)
	     */
	    virtual void* map(GLenum access);

	    template<typename T>
	    T* map(GLenum access);

	    virtual bool unMap(void);

	    virtual GLuint bind() const;

	    virtual void unBind() const;

	    /*--------------------------------------*\
	     |*		Get			*|
	     \*-------------------------------------*/

	public:

	    inline GLenum getTarget() const
		{
		return target;
		}

	    /*--------------------------------------*\
	     |*		Attributs		*|
	     \*-------------------------------------*/

	private:
	    // Inputs
	    GLenum target;
	};

    class CBI_GL VertexBuffer: public Buffer
	{
	public:
	    VertexBuffer();
	};

    class CBI_GL ElementBuffer: public Buffer
	{
	public:
	    ElementBuffer();
	};

    /*----------------------------------------------------------------------*\
 |*			Implementation 					*|
     \*---------------------------------------------------------------------*/

    /*--------------------------------------*\
     |*		template		*|
     \*-------------------------------------*/

    template<typename T>
    T* Buffer::map(GLenum access)
	{
	return (T*)map(access);
	}

    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
