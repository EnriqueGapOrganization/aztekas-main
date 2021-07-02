/**
 * @file /integration/ODE/integration.c
 *
 * @author Alejandro Aguayo-Ortiz
 *
 * @brief Main function for the time integration in the conservative variables
 * \f$ \mathbf{Q} \f$.
 */

#include"main.h"

void ODE_Integration()
{
   //test_module();
rk_ rk;
rk_order = 2;
rk.h = (x1max-x1min)/Nx1;
double x,y,z;
///////////////////////////////////
//////////nu variable/////////////
//////////////////////////////////
for(int i=0; i<Nx1; i++){
x = x1min+i*rk.h;				//x=x1min for i=0
rk.u0=U(1,i);					//step zero
rk.f = f(x,U(1,i),U(2,i),0);			//f(xn,yn)
Runge_Kutta(&rk,1);				//first step
y=U(1,i)+rk.h*f(x,U(1,i),U(2,i),0);
z=U(2,i)+rk.h*f(x,U(1,i),U(2,i),1);
rk.f= f(x+rk.h,y,z,0);				//f(xn+1,yn+k1)
Runge_Kutta(&rk,2);				//second step
U(1,i+1)=rk.u2;				//nu(i+1)=rk(nu(n))
//////////////////////////////////
/////////theta variable///////////
//////////////////////////////////
rk.u0=U(2,i);
rk.f = f(x,U(1,i),U(2,i),1);			//f(xn,yn)
Runge_Kutta(&rk,1);
y=U(1,i)+rk.h*f(x,U(1,i),U(2,i),0);
z=U(2,i)+rk.h*f(x,U(1,i),U(2,i),1);
rk.f= f(x+rk.h,y,z,1);				//f(xn+1,yn+k1)
Runge_Kutta(&rk,2);
U(2,i+1)=rk.u2;

flag(&i);
//flag(&i,x,rk.h);
}
phy_param();
}
