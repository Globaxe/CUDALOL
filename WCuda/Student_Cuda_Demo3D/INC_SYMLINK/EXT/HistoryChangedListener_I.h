#ifndef HISTORY_CHANGED_LISTENER_I_H_
#define HISTORY_CHANGED_LISTENER_I_H_

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

template<class T>
class HistoryChangedListener_I
    {

    public:

	virtual ~HistoryChangedListener_I() {
	    // Nothing
	}

	virtual void onHistoryChanged(const T& event)=0;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
