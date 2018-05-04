#ifndef HISTORY_H_
#define HISTORY_H_

#include "HistoryChangedListener_I.h"

#include <stack>
#include <vector>
#include <algorithm>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

template<class T>
class History
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	History(const T& init) :
		init(init)
	    {
	    stackObject.push(init);
	    }

	virtual ~History()
	    {
	    // Nothing
	    }

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	T push(const T& object)
	    {
	    T last; // call default constructor
	    if (!stackObject.empty())
		{
		last = stackObject.top(); //crash only with intel, if stack is empty!
		}
	    stackObject.push(object);
	    notifyListeners(object);
	    return last;
	    }

	/**
	 * Cant pop last item, ie Init
	 */
	T pop()
	    {
	    if (stackObject.size() > 1)
		{
		stackObject.pop();
		T popedObject = stackObject.top();
		notifyListeners(popedObject);
		return popedObject;
		}
	    else
		{
		return init;
		}

	    }

	void goToInit()
	    {
	    while (stackObject.size() > 1)
		{
		stackObject.pop();
		}
	    notifyListeners(init);
	    }

	void goToPrevious()
	    {
	    if (stackObject.size() > 1)
		{
		pop();
		}

	    //else
	    //rien car il n'y a qu'un seul Domaine restant dans la pile !
	    }

	void addHistoryListener(HistoryChangedListener_I<T>* ptrListener)
	    {
	    vectorListener.push_back(ptrListener);
	    }

	void removeHistoryListener(HistoryChangedListener_I<T>* ptrListener)
	    {
	    vectorListener.erase(std::remove(vectorListener.begin(), vectorListener.end(), ptrListener), vectorListener.end());
	    }

    private:

	void notifyListeners(const T& object)
	    {
	    for (int i = 0; i < vectorListener.size(); i++)
		{
		vectorListener[i]->onHistoryChanged(object);
		}
	    }

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	int size()
	    {
	    return stackObject.size();
	    }

	T getCurrent() const
	    {
	    return stackObject.top();
	    }

	/*--------------------------------------*\
	 |*		Set			*|
	 \*-------------------------------------*/

    public:

	void setCurrent(T& object)
	    {
	    push(object);
	    }

	void setInit(T& object)
	    {
	    init = object;
	    // make stack empty!
	    while (!stackObject.empty())
		{
		stackObject.pop();
		}
	    stackObject.push(init);
	    notifyListeners(init);
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Inputs
	T init;

	// Tools
	std::stack<T> stackObject;
	std::vector<HistoryChangedListener_I<T>*> vectorListener;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
