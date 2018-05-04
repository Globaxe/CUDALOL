#ifndef SHADER_PROGRAMS_H
#define SHADER_PROGRAMS_H

#include "envBilatGL.h"
#include <GL/glew.h>
#include "Shaders.h"

#include <vector>
using std::vector;

/**
 * @Depreciated
 * ShaderPrograms est compos� de plusieurs Shaders (VertexShader et FragmentShader)
 *
 * Creation :
 *
 * 	1 ou plusieurs VertexShader et 0 FragmentShader
 * 	1 ou plusieurs VertexShader et 1 ou plusieur FragmentShader
 *
 * Attention :
 *
 * 	1 seule VertexShader ou FragmentShader avec une m�thode main !
 *
 * Use :
 *	Shaders* vertexShader=loadVertexShader();
 *	Shaders* fragmentShader=loadFragmentShader();
 *
 *	ShaderProgam* shaderProgam=new ShaderProgram();
 *	shaderProgram->attachShader(vertexShader);
 *	shaderProgram->attachShader(fragmentShader);
 *
 *	init :
 *		shaderProgram->init();
 *	display :
 *		shaderProgram->useProgram();
 *		draw();
 *		shaderProgram->unUseProgram();
 *	delete:
 *		shaderProgram->release();
 *
 *TODO : am�lioration gestion des shaders, ne delete pas les shaders car peuvent �tre utilis� dans plusieurs shaderProgram ! Mettre un place syst�me de compteur.
 */
class CBI_GL ShaderPrograms
    {
    public:
	ShaderPrograms();
	virtual ~ShaderPrograms();
	void init();
	void link();
	void release();
	void useProgram();
	void unUseProgram();
	void attachShader(Shaders* shader);
	void removeShader(Shaders* shader);
	GLuint getProgramID() const;
    private :
	vector<Shaders*> tabShaders;
	GLuint programID;
    };

#endif
