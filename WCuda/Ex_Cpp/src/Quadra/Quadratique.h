#pragma once
#include "ABC.h"
#include <cmath>

using namespace std;

class Quadratique
    {
    public:
    double a;
    double b;
    double c;
    double* tab;
    double disc;

    Quadratique(ABC abc)
	{
	this->a = abc.a;
	this->b = abc.b;
	this->c = abc.c;
	this->tab = new double[2];
	disc = pow(b,2)-4*a*c;
	};

    virtual ~Quadratique()
	{
	delete[] tab;
	}

    int solve()
	{
	if(disc<0)
	return 0;

	if(disc==0)
	return 1;

	return 2;
	};

    double* getTabX()
	{
	if (disc > 0)
	    {
	    tab[0] = (-b + sqrt(disc)) / (2*a);
	    tab[1] = (-b - sqrt(disc)) / (2*a);
	    }
	else if (disc == 0)
	    {
	    tab[0] = (-b + sqrt(disc)) / (2*a);
	    tab[1] = (-b + sqrt(disc)) / (2*a);
	    }
	return tab;
	};
    };
