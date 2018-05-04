#ifndef GEOM_SHAPE_H_
#define GEOM_SHAPE_H_

#include "envScene3dGL.h"
#include "Buffer.h"
#include "BufferFactory_I.h"
#include "VertexPointerDescription.h"
#include <vector>
#include "IDGenerator.h"
#include "Bound.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL ShapeGeom: public gl::Object_A
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * primitiveType can be one of this :
	 * 	GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_LINE_STRIP_ADJACENCY, GL_LINES_ADJACENCY,
	 * 	GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES, GL_TRIANGLE_STRIP_ADJACENCY, GL_TRIANGLES_ADJACENCY, GL_PATCHES
	 */
	ShapeGeom(GLenum primitiveType, GLsizei vertexCount, gl::VertexPointerDescription* tabVertexPointerDescription, unsigned int count,
		BufferFactory_I* ptrBufferFactory);

	/**
	 * primitiveType can be one of this :
	 * 	GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_LINE_STRIP_ADJACENCY, GL_LINES_ADJACENCY,
	 * 	GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES, GL_TRIANGLE_STRIP_ADJACENCY, GL_TRIANGLES_ADJACENCY, GL_PATCHES
	 */
	ShapeGeom(GLenum primitiveType, GLsizei vertexCount, std::vector<gl::VertexPointerDescription> tabVertexDescription, BufferFactory_I* ptrBufferFactory);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

    public:

	virtual ~ShapeGeom();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    protected:

	virtual void initGL();

	virtual void releaseGL();

    public:

	GLuint bind() const;

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    private:

	void buildBuffers(BufferFactory_I* ptrBufferFactory);

	void fillVectorVertexPointerDescription(gl::VertexPointerDescription* tabVertexPointerDescription, unsigned count);

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setVertexPointerDescription(int i, gl::VertexPointerDescription& vertexDescription);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	virtual Bound getBound() const;

	std::vector<gl::Buffer*> getBuffers() const;

	std::vector<gl::VertexPointerDescription> getVertexDescription() const;

	gl::Buffer* getBuffer(unsigned int i);

	gl::VertexPointerDescription getVertexPointerDescription(unsigned int i) const;

	inline unsigned int getBufferCount() const
	    {
	    return tabVertexDescription.size();
	    }

	inline GLsizei getVertexCount() const
	    {
	    return vertexCount;
	    }

	inline GLenum getPrimitiveType() const
	    {
	    return primitiveType;
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Inputs
	GLenum primitiveType;
	GLsizei vertexCount;
	std::vector<gl::VertexPointerDescription> tabVertexDescription;

	// Output
	std::vector<gl::Buffer*> tabBuffer;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
