#ifndef SHAPE_GEOM_INDEXED_ANIMABLE_H_
#define SHAPE_GEOM_INDEXED_ANIMABLE_H_

#include "ShapeGeomAnimable_I.h"
#include "ShapeIndexedGeom.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL ShapeIndexedGeomAnimable: public ShapeIndexedGeom, public ShapeGeomAnimable_I
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
	ShapeIndexedGeomAnimable(GLenum primitiveType, GLsizei vertexCount, GLsizei elementCount, gl::VertexPointerDescription* tabVertexPointerDescription,
		unsigned int count, GLenum typeElement, BufferFactory_I* ptrBufferFactory);

	/**
	 * GLenum typeElement must be one of :
	 *	GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT, or GL_UNSIGNED_INT
	 *
	 * primitiveType can be one of this :
	 * 	GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_LINE_STRIP_ADJACENCY, GL_LINES_ADJACENCY,
	 * 	GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES, GL_TRIANGLE_STRIP_ADJACENCY, GL_TRIANGLES_ADJACENCY, GL_PATCHES
	 */
	ShapeIndexedGeomAnimable(GLenum primitiveType, GLsizei vertexCount, GLsizei elementCount,
		std::vector<gl::VertexPointerDescription> tabVertexPointerDescription, GLenum typeElement, BufferFactory_I* ptrBufferFactory);

	virtual ~ShapeIndexedGeomAnimable();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    protected:

	virtual void initGL();

	virtual void releaseGL();

	virtual void fillBufferGL();


    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
