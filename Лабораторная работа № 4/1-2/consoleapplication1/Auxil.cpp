#include "stdafx.h"


Auxil::Auxil()
{
    srand( (unsigned)time( NULL ));    
};

double Auxil::get_double(double rmin, double rmax)
{
   return ((double)(rand()%(int)(rmax-rmin+1) + rmin));
}; 

int Auxil::get_int(int rmin, int rmax)
{
   return (int) get_double((double)rmin,(double)rmax);
};

