#include"main.h"
void integration(double x, double *y, double(*f)(double x, double *y, int i), int dim, rk_ rk);
double f(double x, double *y, int i);
int test_module(){
	FILE *data;
	data=fopen("data.dat", "w");
	rk_ rk;
	rk.h = (x1max-x1min)/Nx1;
	int dim=2;
	double y[dim];
	double x;
	for(int i=0;i<Nx1;i++){
		x=x1min+i*rk.h;
		for(int j=0;j<dim; j++) y[j]=U(j,i);
		fprintf(data,"%.8E\t%.8E\n",y[0],y[1]);
		integration(x,y,f,dim,rk);
		for(int j=0;j<dim; j++) U(j,i+1)=y[j];
		
	}
}
void integration(double x, double *y, double(*f)(double x, double *y, int i), int dim, rk_ rk){
	rk_order =2;
	double aux[dim], result[dim];
	for(int a=0; a<dim; a++){
		rk.u0=*(y+a);
		rk.f=f(x,y,a);
		Runge_Kutta(&rk,1);
		for(int b=0; b<dim; b++) aux[b]=*(y+b)+rk.h*f(x,y,b);
		rk.f=f(x,aux,a);
		Runge_Kutta(&rk,2);
		result[a]=rk.u2;
	}
	for(int c=0; c<dim; c++) *(y+c)=result[c];
}

double f(double x, double *y, int i){
    if (i==0) 	return(cos(x));
    if (i==1) 	return(-sin(x));
}