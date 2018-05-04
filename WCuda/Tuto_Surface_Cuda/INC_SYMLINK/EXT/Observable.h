#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include <vector>
#include <algorithm>
#include "Observer_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

template<class T>
class Observable
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	virtual ~Observable()
	    {
	    // Nothing
	    }

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void addObserver(Observer_I<T>* ptrObserver)
	    {
	    vectorObservers.push_back(ptrObserver);
	    }

	void removeObserver(Observer_I<T>* ptrObserver)
	    {
	    vectorObservers.erase(std::remove(vectorObservers.begin(), vectorObservers.end(), ptrObserver), vectorObservers.end());
	    }

	void notifyObservers()
	    {
	    for (int i = 0; i < vectorObservers.size(); i++)
		{
		vectorObservers[i]->onUpdate((T*)this);
		}
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	std::vector<Observer_I<T>*> vectorObservers;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
