#ifndef BRAIN_LOADER_H_
#define BRAIN_LOADER_H_

#include "envGLSurface.h"
#include "BrainData.h"

#include <string>
#include <algorithm>
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

#ifdef _WIN32
    static string DEFAULT_DIR="../../Data/BrainBin";
#else
    static string DEFAULT_DIR="/opt/cbi/data/Brain";
#endif

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL BrainLoader
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	BrainLoader(string dataDirectory = DEFAULT_DIR);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	BrainData loadBrain7899();

	BrainData loadBrain64370();

	BrainData loadHead17760();

	static bool loadVertices(string filename, float** ptrTabVertices, unsigned int* verticeCount);

	static bool loadTriangles(string filename, unsigned int** ptrTabTriangles, unsigned int* triangleCount);

	static void destroyBrainData(BrainData& brainData);

    private:

	/**
	 * conversion Endianess
	 */
	template<class T>
	static void endswap(T *objp)
	    {
	    unsigned char *memp = reinterpret_cast<unsigned char*>(objp);
	    std::reverse(memp, memp + sizeof(T));
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	//Inputs
	string dataDirectory;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
