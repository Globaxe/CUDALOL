#include <iostream>

#include "SceneCubeCreator.h"


#include "RipplingProvider.h"
#include "MandelbrotProvider.h"
#include "MandelbrotProvider2.h"
#include "MandelbrotProvider3.h"
#include "MandelbrotProvider4.h"
#include "RayTracingProvider.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

SceneCubeCreator::SceneCubeCreator()
    {
    createImages();
    createScene();
    }

SceneCubeCreator::~SceneCubeCreator()
    {
    delete ptrImage1;
    delete ptrImage2;
    delete ptrImage3;
    delete ptrImage4;
    delete ptrImage5;
    delete ptrImage6;

    delete ptrScene;
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

SceneCube* SceneCubeCreator::getScene()
    {
    return ptrScene;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void SceneCubeCreator::createImages()
    {

    //on a pas 6 tp donc prendre un mandlebrot et changer le domaine de math par exemple
    //lancer mandlebrot et f2 pour ShowDomaine

    ptrImage1 = RipplingProvider().createImageGL();
    ptrImage2 = MandelbrotProvider().createImageGL();

    ptrImage3 = RayTracingProvider().createImageGL();
    ptrImage4 = MandelbrotProvider2().createImageGL();
    ptrImage5 = MandelbrotProvider3().createImageGL();
    ptrImage6 = MandelbrotProvider4().createImageGL();
    //ptrImage4 = DamierRGBAFloatProvider().createImageGL();
    //ptrImage5 = DamierHSBAFloatProvider().createImageGL(); //ko, FIXME JST shader
    //ptrImage6 = DamierHueFloatProvider().createImageGL(); // ko, FIXME JST shader
    }

void SceneCubeCreator::createScene()
    {
    ptrScene = new SceneCube(ptrImage1, ptrImage2, ptrImage3, ptrImage4, ptrImage5, ptrImage6);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

