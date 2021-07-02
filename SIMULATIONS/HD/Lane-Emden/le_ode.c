#include"main.h"

double  f(double x, double y, double z, int i){
if (i==0) return(pow(z,POL)-3.0*y);		//dnu/dx =	theta^n -3*nu
if (i==1) return(-exp(2.0*x)*y); 		//dtheta/dx =	-nu*exp^2x
}
