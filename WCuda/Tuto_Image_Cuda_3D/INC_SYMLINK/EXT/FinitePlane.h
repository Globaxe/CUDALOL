#ifndef FINITEPLANE_H_
#define FINITEPLANE_H_

#include "envScene3dGL.h"
#include <glm/glm.hpp>
#include "Observable.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Finite math plane define by his point p and two coplanar vectors, u and v.
 *
 * If the plane is dark, you need maybe to inverte u and v. (regle du tire bouchon)
 */
class CBI_SCENE3D_GL FinitePlane: public Observable<FinitePlane>
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * p point au centre
	 * u,v vecteur
	 *
	 * plan define par p et u,v autour de p dans toutes les directions
	 * plan de "largeur" et "longueur" 2u et 2v
	 *
	 * see too static create
	 */
	FinitePlane(glm::vec3 pCentre, glm::vec3 u, glm::vec3 v);

	/**
	 * Warning : p au centre!
	 */
	FinitePlane(glm::vec3 pCentre, glm::vec3 u, glm::vec3 v, float du, float dv);

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	/**
	 * pCentre
	 */
	void setP(glm::vec3 pCentre);

	void setU(glm::vec3 u);

	void setV(glm::vec3 v);

	void setUV(glm::vec3 u, glm::vec3 v);

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline glm::vec3 getP() const
	    {
	    return p;
	    }

	inline glm::vec3 getU() const
	    {
	    return u;
	    }

	inline glm::vec3 getV() const
	    {
	    return v;
	    }

	/**
	 * N = UxV
	 */
	inline glm::vec3 getN() const
	    {
	    return n;
	    }

	/**
	 * p point au coin
	 * u,v vecteur
	 *
	 * plan define par p et u,v
	 * plan de "largeur" et "longueur" u et v
	 *
	 * see too constructor
	 */
	static FinitePlane* create(glm::vec3 pCoin, glm::vec3 u, glm::vec3 v);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Inputs
	glm::vec3 p;
	glm::vec3 u;
	glm::vec3 v;

	// Outputs
	glm::vec3 n;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
