#pragma once
#include "Sphere.h"
class SphereCreator
    {
	/*--------------------------------------*\
|*
	 Constructor
	 *|
	 \*-------------------------------------*/
    public:
	SphereCreator(int nbSpheres, int w, int h, int bord = 200);
	virtual ~SphereCreator(void);

	/*--------------------------------------*\
|*
	 Methodes
	 *|
	 \*-------------------------------------*/
    public:
	Sphere* getTabSphere();
    private:
	void createSphereAll(void);
	void createSphereBack();
	void createSphereFront();
	void createSphereAleatoire();
	int rayonMax();
	/*--------------------------------------*\
|*
	 Attributs
	 *|
	 \*-------------------------------------*/
    private:
// Inputs
	int nbSpheres;
	int w;
	int h;
	int bord;
// Tools
	Sphere* tabSphere;
	static const int ZMIN = 2000;
	static const int ZMAX = 3000;
    };
