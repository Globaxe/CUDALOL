#ifndef BRAIN_I_H_
#define BRAIN_I_H_

#include "BrainData.h"
#include "MeshIndexed_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL Brain_I: public MeshIndexed_I
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/


    public:

	Brain_I(BrainData& brainData, MeshColorModel colorModel, int colorFormat);

	virtual ~Brain_I();

	/*--------------------------------------*\
 |*		Surcharge		*|
	 \*-------------------------------------*/

    public :

	virtual void fillRawVertex(void* prTabVertices, void* ptrDevTabColor);

	void initTriangles(unsigned int* tabElements, unsigned int elementCount);

	/*--------------------------------------*\
 |*		Attributs		*|
	 \*-------------------------------------*/

    public:

	// Inputs
	const BrainData brainData;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
