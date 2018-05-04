#ifndef MESH_I_H_
#define MESH_I_H_

#include "envGLSurface.h"
#include "Bound.h"
#include "MeshColorModel.h"
#include "Graphic2D.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL Mesh_I
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Mesh_I(unsigned int triangleCount,MeshColorModel colorModel,int colorFormat, const Bound& initialBound);

	virtual ~Mesh_I();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	/**
	 * A redefinir par l'utilisateur
	 */
	virtual void fillRawVertex(void* prTabVertices, void* ptrDevTabColor)=0;

	/**
	 * A redefinir par l'utilisateur
	 */
	virtual void animationStep(bool& isNeedUpdateView);

	/**
	 * A redefinir par l'utilisateur
	 */
	virtual void paintPrimitives(Graphic2D& ptrGraphic2D);

	/**
	 * A redefinir par l'utilisateur
	 */
	virtual void onBoundChanged();

	/*--------------------------------------*\
	|*		Set			*|
	 \*-------------------------------------*/

	void setBound(const Bound& domaineMath);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

	inline Bound getBound() const
	    {
	    return bound;
	    }

	/**
	 * 3 or 4
	 */
	unsigned int getColorComponantCount() const;

	virtual size_t getColorSize() const=0;

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    public:

	// Inputs
	const unsigned int triangleCount;
	const MeshColorModel colorModel;
	const int colorFormat; //GL_FLOAT, GL_UNSIGNED_BYTE

	// Tools
	const unsigned int vertexCount;

    protected:

	// Inputs
	Bound bound;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
