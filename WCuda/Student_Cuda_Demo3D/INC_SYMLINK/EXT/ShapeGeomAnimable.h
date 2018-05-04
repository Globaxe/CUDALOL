#ifndef SHAPE_GEOM_ANIMABLE_H_
#define SHAPE_GEOM_ANIMABLE_H_

#include "ShapeGeom.h"
#include "ShapeGeomAnimable_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SCENE3D_GL ShapeGeomAnimable: public ShapeGeom, public ShapeGeomAnimable_I
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
	ShapeGeomAnimable(GLenum primitiveType,GLsizei vertexCount,gl::VertexPointerDescription* tabVertexPointerDescription, unsigned int count,BufferFactory_I* ptrBufferFactory);

	/**
	 * primitiveType can be one of this :
	 * 	GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_LINE_STRIP_ADJACENCY, GL_LINES_ADJACENCY,
	 * 	GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES, GL_TRIANGLE_STRIP_ADJACENCY, GL_TRIANGLES_ADJACENCY, GL_PATCHES
	 */
	ShapeGeomAnimable(GLenum primitiveType, GLsizei vertexCount, std::vector<gl::VertexPointerDescription> tabVertexDescription, BufferFactory_I* ptrBufferFactory);

	virtual ~ShapeGeomAnimable();

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
