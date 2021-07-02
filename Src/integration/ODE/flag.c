#include"main.h"

void flag(int *a){

int i=*a;

if(U(2,i+1)<0){
for (int k=i; k<Nx1; k++){
U(1,k+1)=0.0;
U(2,k+1)=0.0;
}
*a=Nx1;
}

if( U(2,i+1)>ERR && i==(Nx1-1)){
printf("ERROR: Integration stoped before reaching the star boundary.\nRedefine your domain limits.\n");
}
}
