#include"main.h"

int test_module()
{
rk_ rk;
rk_order = 2;
rk.h = (x1max-x1min)/Nx1;
double x,y,z;
//step = (x1max-x1min)/Nx1;
///////////////////////////////////
//////////nu variable/////////////
//////////////////////////////////
for(int i=0; i<=Nx1; i++){
x = x1min+i*rk.h;
//x = log(x1min+i*step);
//rk.h = log(x1min+(i+1)*step)-log(x1min+i*step);				//x=x1min for i=0
rk.u0=U(0,i);					//step zero
rk.f = f(x,U(0,i),U(1,i),0);			//f(xn,yn)
Runge_Kutta(&rk,1);				//first step
y=U(0,i)+rk.h*f(x,U(0,i),U(1,i),0);
z=U(1,i)+rk.h*f(x,U(0,i),U(1,i),1);
rk.f= f(x+rk.h,y,z,0);				//f(xn+1,yn+k1)
Runge_Kutta(&rk,2);				//second step
U(0,i+1)=rk.u2;				//nu(i+1)=rk(nu(n))
//////////////////////////////////
/////////theta variable///////////
//////////////////////////////////
rk.u0=U(1,i);
rk.f = f(x,U(0,i),U(1,i),1);			//f(xn,yn)
Runge_Kutta(&rk,1);
y=U(0,i)+rk.h*f(x,U(0,i),U(1,i),0);
z=U(1,i)+rk.h*f(x,U(0,i),U(1,i),1);
rk.f= f(x+rk.h,y,z,1);				//f(xn+1,yn+k1)
Runge_Kutta(&rk,2);
U(1,i+1)=rk.u2;
//////////////////////////////////
////////cambio de variable////////
//////////////////////////////////
U(2,i)=exp(x1min+rk.h*i);			//chi=exp(x)
///////////////////////////////////
//////////Stellar radio////////////
///////////////////////////////////
if(U(1,i+1)<0){
for (int k=i; k<=Nx1; k++){
U(0,k+1)=0.0;
U(1,k+1)=0.0;
}}
}
////////////////////////////////////
/////////variable de masa///////////
////////////////////////////////////
for(int j=0; j<=Nx1; j++){
U(0,j)=U(0,j)*pow(U(2,j),3);
}
}
double  f(double x, double y, double z, int i){
if (i==0) return(pow(z,POL)-3.0*y);		//dnu/dx =	theta^n -3*nu
if (i==1) return(-exp(2.0*x)*y); 		//dtheta/dx =	-nu*exp^2x
}
