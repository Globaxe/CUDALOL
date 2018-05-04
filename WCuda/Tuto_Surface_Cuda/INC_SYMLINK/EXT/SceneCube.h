#pragma once

#include "ScenePlan.h"

using glm::vec3;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class SceneCube: public ScenePlan
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SceneCube(Image_I* ptrImage1,Image_I* ptrImage2,Image_I* ptrImage3,Image_I* ptrImage4,Image_I* ptrImage5,Image_I* ptrImage6);

	virtual ~SceneCube();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	/*--------------------------------------*\
 |*		Methodes		*|
	 \*-------------------------------------*/

    private:

	void createPlans();

	void createPlan1(Image_I* ptrImage);
	void createPlan2(Image_I* ptrImage);
	void createPlan3(Image_I* ptrImage);
	void createPlan4(Image_I* ptrImage);
	void createPlan5(Image_I* ptrImage);
	void createPlan6(Image_I* ptrImage);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Input
	Image_I* ptrImage1;
	Image_I* ptrImage2;
	Image_I* ptrImage3;
	Image_I* ptrImage4;
	Image_I* ptrImage5;
	Image_I* ptrImage6;

	// Tools
	FinitePlane* ptrPlane1;
	FinitePlane* ptrPlane2;
	FinitePlane* ptrPlane3;
	FinitePlane* ptrPlane4;
	FinitePlane* ptrPlane5;
	FinitePlane* ptrPlane6;

	// Tools static
	static vec3 X; //(1.0f, 0.0f, 0.0f); // vecteur
	static vec3 Y; //(0.0f, 1.0f, 0.0f); // vecteur
	static vec3 Z; //(0.0f, 0.0f, 1.0f);  // vecteur

	static vec3 ORIGINE; //(0.0f, 1.0f, 0.0f);  // point

	static vec3 TRANSLATION; // vecteur translation, pour rotation centre cube

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
