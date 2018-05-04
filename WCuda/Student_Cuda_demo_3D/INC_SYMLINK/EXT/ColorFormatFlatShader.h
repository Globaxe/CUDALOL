#ifndef COLORFORMATFLATSHADER_H_
#define COLORFORMATFLATSHADER_H_

#include "ShaderProgram.h"
#include "ColorFormat.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * HSB or RGB coloring without lighting component
 *
 * Input : ColorFormat
 * Output : Color compute in RGB or HSB without lighting only flat color
 */
class CBI_SCENE3D_GL ColorFormatFlatShader: public gl::ShaderProgram
    {
    public:

	ColorFormatFlatShader(ColorFormat colorFormat);

	virtual ~ColorFormatFlatShader();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    private :

	void loadShaders(ColorFormat colorFormat);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	gl::Shader* ptrVertexShader;
	gl::Shader* ptrFragmentShader;
	gl::Shader* ptrFragmentShaderColorMode;


    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
