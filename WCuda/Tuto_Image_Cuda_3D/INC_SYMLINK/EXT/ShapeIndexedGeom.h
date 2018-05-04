#ifndef SHAPE_INDEXED_GEOM_H_
#define SHAPE_INDEXED_GEOM_H_

#include "ShapeGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL ShapeIndexedGeom: public gl::Object_A
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * GLenum typeElement must be one of :
	 *	GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT, or GL_UNSIGNED_INT
	 *
	 * primitiveType can be one of this :
	 * 	GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_LINE_STRIP_ADJACENCY, GL_LINES_ADJACENCY,
	 * 	GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES, GL_TRIANGLE_STRIP_ADJACENCY, GL_TRIANGLES_ADJACENCY, GL_PATCHES
	 */
	ShapeIndexedGeom(GLenum primitiveType, GLsizei vertexCount, GLsizei elementCount, gl::VertexPointerDescription* tabVertexPointerDescription,
		unsigned int count, GLenum typeElement, BufferFactory_I* ptrBufferFactory);

	/**
	 * GLenum typeElement must be one of :
	 *	GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT, or GL_UNSIGNED_INT
	 *
	 * primitiveType can be one of this :
	 * 	GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_LINE_STRIP_ADJACENCY, GL_LINES_ADJACENCY,
	 * 	GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES, GL_TRIANGLE_STRIP_ADJACENCY, GL_TRIANGLES_ADJACENCY, GL_PATCHES
	 */
	ShapeIndexedGeom(GLenum primitiveType, GLsizei vertexCount, GLsizei elementCount,
		std::vector<gl::VertexPointerDescription> tabVertexPointerDescription, GLenum typeElement, BufferFactory_I* ptrBufferFactory);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

    public:

	virtual ~ShapeIndexedGeom();

    public:

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

	/*--------------------------------------*\
 |*		Set			*|
	 \*-------------------------------------*/

    public:

	/**
	 * Delegate methode
	 */
	void setVertexPointerDescription(int i, gl::VertexPointerDescription& vertexDescription);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	virtual Bound getBound() const;

	/**
	 * GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT, or GL_UNSIGNED_INT
	 */
	GLenum getElementType() const;

	gl::Buffer* getElementBuffer();

	/**
	 * Delegate methode
	 */
	std::vector<gl::Buffer*> getBuffers() const;
	/**
	 * Delegate methode
	 */
	std::vector<gl::VertexPointerDescription> getVertexDescription() const;
	/**
	 * Delegate methode
	 */
	gl::Buffer* getBuffer(unsigned int i);
	/**
	 * Delegate methode
	 */
	gl::VertexPointerDescription getVertexPointerDescription(unsigned int i) const;

	/**
	 * Delegate methode
	 */
	inline unsigned int getBufferCount() const
	    {
	    return ptrShapeGeom->getBufferCount();
	    }

	/**
	 * Delegate methode
	 */
	inline GLenum getPrimitiveType() const
	    {
	    return ptrShapeGeom->getPrimitiveType();
	    }

	/**
	 * Delegate methode
	 */
	inline GLsizei getVertexCount() const
	    {
	    return ptrShapeGeom->getVertexCount();
	    }

	inline GLsizei getElementCount() const
	    {
	    return elementCount;
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Input
	GLenum typeElement; //GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT, or GL_UNSIGNED_INT
	GLsizei elementCount;

	// Output
	gl::Buffer* elementBuffer;
	ShapeGeom* ptrShapeGeom;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
