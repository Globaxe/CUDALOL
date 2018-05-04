#ifndef BRAINGEOMBASE_H_
#define BRAINGEOMBASE_H_

#include "Brain_I.h"
#include "MeshIndexedGeomBase.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL BrainGeomBase : public MeshIndexedGeomBase
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	BrainGeomBase(Brain_I* ptrBrain, BufferFactory_I* ptrBufferFactory, NormalIndexedCompute_I* ptrNormalCompute);

	virtual ~BrainGeomBase();

	/*--------------------------------------*\
	|*		Surcharge		*|
	 \*-------------------------------------*/

    protected:

	virtual void initVertexBuffer();

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
