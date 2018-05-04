#pragma once
#include <iostream>

using std::ostream;

struct ABC
    {
	/*-------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/
    public:
	ABC(double a = 0, double b = 0, double c = 0)
	    {
	    this->a = a;
	    this->b = b;
	    this->c = c;
	    }
    public:
	double a;
	double b;
	double c;

	friend ostream &operator<<(ostream &flux, const ABC &abc);
    };

ostream &operator<<(ostream &flux, const ABC &abc)
    {
    return flux << "a :" << abc.a << "|b :" << abc.b << "|c :" << abc.c;
    }
