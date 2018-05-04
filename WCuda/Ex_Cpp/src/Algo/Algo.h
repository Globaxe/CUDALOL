#pragma once

class Algo
    {
    public:
	virtual ~Algo(){};
	virtual int h(int x)=0;
	int phi(int x)
	    {
	    return 2*x;
	    }
	int use(int x)
	    {
	    return phi(h(x));
	    }
    };

