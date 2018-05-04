#ifndef CUDA_BUFFER_H_
#define CUDA_BUFFER_H_

#include "envGLSurfaceCudas.h"

#include "Buffer.h"
#include "cuda.h"
#include "cuda_runtime.h"
#include "cuda_gl_interop.h" //link between GL and Cuda

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Utility class to handle the binding with cudaGraphicsResource and OpenGL
 */
class CBI_SURFACE_GL_CUDA CudaBuffer: public gl::Buffer
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * See official documentation for more target possibilities depending of the OpenGL version you want to use.
	 *
	 * @param target OpenGL 2.0 (GL_ARRAY_BUFFER, GL_ELEMENT_ARRAY_BUFFER, GL_PIXEL_PACK_BUFFER, or GL_PIXEL_UNPACK_BUFFER)
	 *
	 * @param flags :
	 * 	cudaGraphicsRegisterFlagsNone
	 * 	cudaGraphicsRegisterFlagsReadOnly
	 * 	cudaGraphicsRegisterFlagsWriteDiscard
	 */
	CudaBuffer(GLenum target, unsigned int flags = cudaGraphicsRegisterFlagsNone, cudaStream_t stream = 0);

	virtual ~CudaBuffer();

	/*--------------------------------------*\
 |*		Surcharge		*|
	 \*-------------------------------------*/

    protected:

	virtual void initGL();

	virtual void releaseGL();

    public:

	/**
	 * @param access
	 * 	GL_READ_ONLY
	 * 	GL_WRITE_ONLY
	 * 	GL_READ_WRITE)
	 */
	virtual void* map(GLenum access);

	virtual bool unMap(void);

	/*--------------------------------------*\
 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void memset0();

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setCudaStream(cudaStream_t stream);

	void setFlags(unsigned int flags);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline cudaStream_t getCudaStream() const
	    {
	    return stream;
	    }

	inline unsigned int getFlags() const
	    {
	    return flags;
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	cudaStream_t stream;
	unsigned int flags;

	// Tools
	cudaGraphicsResource* ptrCudaBufferResource;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
