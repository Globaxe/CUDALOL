#pragma once

#include <iostream>
#include "ImageOption.h"

#include "GLUTImageViewers_GPU.h"
#include "Provider_I_GPU.h"

using std::cout;
using std::endl;
using std::string;

// astuce: permet de travailler avec une m�thode static sans classe derivant interface
// meme code pour cpu gpu :

/**
 * TProvider doit fournir
 *
 * 	Image_I*
 *
 * see Image_GPU and Provider_I_GPU
 */
namespace gpu
    {
    template<class TProvider>
    class Viewer
	{

	    /*--------------------------------------*\
	|*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    Viewer(ImageOption imageOption, int pxFrame = 0, int pyFrame = 0) :
		    ptrImage(TProvider().createImageGL()), glutViewer(ptrImage, imageOption, pxFrame, pyFrame)
		{
		// Rien
		}

	    ~Viewer()
		{
		delete ptrImage; // car TProvider::createImageGL() fournit un pointeur d'un objet dynamique
		}
	    
	    /*--------------------------------------*\
	|*		Methodes		*|
	     \*-------------------------------------*/

	public:

	    void setViewerSize(int w, int h)
		{
		glutViewer.getGLUTWindowImage()->setSize(w, h);
		}

	    void setViewerPosition(int px, int py)
		{
		glutViewer.getGLUTWindowImage()->setPosition(px, py);
		}

	    /**
	     * w,h
	     */
	    int2 getViewerSize()
		{
		int h = glutViewer.getGLUTWindowImage()->getFrameHeight();
		int w = glutViewer.getGLUTWindowImage()->getFrameWidth();

		int2 size =
		    {
		    w, h
		    };

		return size;
		}

	    /**
	     * px,py
	     */
	    int2 getViewerPosition()
		{
		int px = glutViewer.getGLUTWindowImage()->getFramePositionX();
		int py = glutViewer.getGLUTWindowImage()->getFramePositionY();

		int2 position =
		    {
		    px, py
		    };

		return position;
		}

	    GLUTImageViewers* getGlutImageViewers()
		{
		return &glutViewer;
		}

	    GLUTWindowImage* getGLUTWindowImage()
		{
		return glutViewer.getGLUTWindowImage();
		}

	    Image_I* getImage()
		{
		return ptrImage;
		}

	    /*--------------------------------------*\
	|*		Attributs		*|
	     \*-------------------------------------*/

	private:
	    
	    // Input
	    Image_I* ptrImage;

	    // Tools
	    GLUTImageViewers glutViewer;
	    
	};
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
