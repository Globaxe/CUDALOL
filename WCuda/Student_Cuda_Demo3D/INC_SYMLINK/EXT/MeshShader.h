#ifndef CORE_HEADER_VIEW_GL_MESHSHADER_H_
#define CORE_HEADER_VIEW_GL_MESHSHADER_H_

#include "envGLSurface.h"
#include <string>
#include "ShaderLoaders.h"
#include "ShaderPrograms.h"
#include "MeshColorModel.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_SURFACE_GL MeshShader
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	MeshShader(MeshColorModel colorModel);

	virtual ~MeshShader();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public :

	void init();

	void dispose();

    private :

	void loadShaderFromFile(MeshColorModel colorModel);

	void loadShader(MeshColorModel colorModel);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public :

	ShaderPrograms* getShader(bool isLightingEnable);

	inline ShaderPrograms* getShader()
	    {
	    return shader;
	    }

	inline ShaderPrograms* getShaderNoLight()
	    {
	    return shaderNoLigth;
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Tools
	ShaderPrograms* shader;
	ShaderPrograms* shaderNoLigth;
	Shaders* shaderColor;
	Shaders* shaderColorNoLight;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
