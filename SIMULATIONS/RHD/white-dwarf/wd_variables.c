#include"main.h"

void phy_param(){

for(int i=0; i<=Nx1; i++){

U(0,i)=exp(x1min+ (x1max-x1min)*i/Nx1);			//chi=exp(x)
U(1,i)=0.721459*U(1,i)*pow(U(0,i),3);				//mass=0.721459*nu*chi³
U(0,i)=3.88466*U(0,i)/FC;					//radio=3.88466*chi/fc
}

}
