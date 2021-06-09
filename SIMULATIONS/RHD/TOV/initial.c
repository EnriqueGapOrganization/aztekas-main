/*
 * File Name : initial.c
 * Description : aztekas initial module for Shock-Tube
 * Creation Date : 26-09-2019
 * Last Modified : 18-02-2020 09:43:01
 * Created By : Alejandro Aguayo-Ortiz
 */

#include"main.h"

void Initial()
{
   //Initialize grid.time
   grid.time = 0.0;

   //Initialize dt
   dt = 0.0;

#if DIM == 1 
   /////////////////////////////
   //-------Riemann-1D--------//
   /////////////////////////////	
   for(int i = 0; i <= Nx1; i++)
   {
   	U(RHO,i) = 1.0/3.0 - POL*pow(exp(x1min),2.0)/30.0 + POL*(8.0*POL-5.0)*pow(exp(x1min),4.0)/2520.0;
	U(PRE,i) = 1.0 - pow(exp(x1min),2.0)/6.0 + POL*pow(exp(x1min),4.0)/120.0;
	U(VX1,i) = 0.0;
      /*if(grid.X1[i] < x_0)
      {
         U(RHO,i) = rhol;
         U(PRE,i) = pl;
         U(VX1,i) = vx1l;
      }
      else
      {
         U(RHO,i) = rhor;
         U(PRE,i) = pr;
         U(VX1,i) = vx1r;
      }*/
   }

#elif DIM == 2

   /////////////////////////////
   //-------Riemann-2D--------//
   /////////////////////////////

   #if INTERFACE == HORIZONTAL
   for(int j = 0; j <= Nx2; j++)
   {
      for(int i = 0; i <= Nx1; i++)
      {
         if(grid.X1[i] < x_0)
         {
            U(RHO,i,j) = rhol;
            U(PRE,i,j) = pl;
            U(VX1,i,j) = vx1l;
            U(VX2,i,j) = vx2l;
         }
         else 
         {
            U(RHO,i,j) = rhor;
            U(PRE,i,j) = pr;
            U(VX1,i,j) = vx1r;
            U(VX2,i,j) = vx2r;
         }
      }
   }
   #elif INTERFACE == VERTICAL
   for(int j = 0; j <= Nx2; j++)
   {
      for(int i = 0; i <= Nx1; i++)
      {
         if(grid.X2[j] > x_0)
         {
            U(RHO,i,j) = rhol;
            U(PRE,i,j) = pl;
            U(VX1,i,j) = vx1l;
            U(VX2,i,j) = vx2l;
         }
         else 
         {
            U(RHO,i,j) = rhor;
            U(PRE,i,j) = pr;
            U(VX1,i,j) = vx1r;
            U(VX2,i,j) = vx2r;
         }
      }
   }
   #elif INTERFACE == DIAGONAL
   for(int j = 0; j <= Nx2; j++)
   {
      for(int i = 0; i <= Nx1; i++)
      {
         if(grid.X1[i] + grid.X2[j] - 1 < 0.0)
         {
            U(RHO,i,j) = rhol;
            U(PRE,i,j) = pl;
            U(VX1,i,j) = vx1l;
            U(VX2,i,j) = vx2l;
         }
         else 
         {
            U(RHO,i,j) = rhor;
            U(PRE,i,j) = pr;
            U(VX1,i,j) = vx1r;
            U(VX2,i,j) = vx2r;
         }
      }
   }
   #endif
#endif
}
