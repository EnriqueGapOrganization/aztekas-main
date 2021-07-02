#include"main.h"

double  f(double x, double y, double z, int i)
{
if (i==0) return(pow(z,3.0/2.0)*pow((z+(2.0/FC)),3.0/2.0)-3.0*y);		//dnu/dx
if (i==1) return(-y*exp(2.0*x));							//dtheta/dx
}
