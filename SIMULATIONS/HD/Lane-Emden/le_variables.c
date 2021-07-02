#include"main.h"

void phy_param(){

for(int i=0; i<=Nx1; i++){

U(0,i)=exp(x1min+ (x1max-x1min)*i/Nx1);			//chi=exp(x)
U(1,i)=U(1,i)*pow(U(0,i),3);					//mu=nu*chi³
}

}
