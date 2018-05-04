#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include "Animatorable_I.h"
#include "envBilatDisplayable.h"

#include <chrono>
#include <vector>
#include <mutex>
#include <atomic>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_DISPLAYABLE Animator
    {

	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    private:

	Animator();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void pause();

	void resume();

	/**
	 * Thread-safe
	 */
	void animate();

	/**
	 * Thread-safe
	 */
	bool registerAnimable(Animatorable_I* ptrAnimable);

	/**
	 * Thread-safe
	 */
	bool unregisterAnimable(Animatorable_I* ptrAnimable);

	/*--------------------------------------*\
 |*		Is			*|
	 \*-------------------------------------*/

    public:

	inline bool isRunning() const
	    {
	    return running;
	    }

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

    public:

	/**
	 * Thread-safe
	 */
	static Animator* getInstance();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	std::vector<Animatorable_I*> vectorAnimable;
	std::mutex mutexVectorAnimable;
	std::atomic<bool> running;

	static std::mutex mutexInstance;
	static Animator* instance;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
