#ifndef TEXT_2D_H
#define TEXT_2D_H

#include "Primitive_A.h"
#include "Font_A.h"
#include <string>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_DISPLAYABLE Text2D: public Primitive_A
    {
    public:

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

	Text2D(int x, int y, std::string texte);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

	virtual ~Text2D();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Override
	 */
	void accept(PrimitiveVisitor_I &visitor);

	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public:

	inline int getX() const
	    {
	    return x;
	    }

	inline int getY() const
	    {
	    return y;
	    }

	inline std::string getText() const
	    {
	    return texte;
	    }

	/*--------------------------------------*\
 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setXY(int x, int y);

	void setText(std::string text);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    public:

	//Input
	std::string texte;
	int x;
	int y;
    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
