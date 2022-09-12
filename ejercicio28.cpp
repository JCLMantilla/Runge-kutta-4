#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


/*We declare the functions that we are going to use*/

void rk4(int n, float c);
double fx(double vx, double vy, float c);
double fy(double vx, double vy, float c);

int main(){

    int n=200; /*Num of iterations for the rk4*/
    float c=0.7; /*Friction coefficient*/
    rk4(n,c);
    return 0;
}




void rk4(int n, float c){
    double h=0.01; /*Sensibility of step*/
    /*We initialize the velocity and position arrays */
    double *X=new double[n];
    double *Y=new double[n];
    double *VX=new double[n];
    double *VY=new double[n];   
    /*Initial conditions*/
    double x_ini=1.0;
    double vx_ini=10.0;
    X[0]=x_ini;
    VX[0]=vx_ini;
    
    double y_ini=10.0;
    double vy_ini=10.0;
    Y[0]=y_ini;
    VY[0]=vy_ini;

    /*Loop for the RK4*/
    for(int i=0;i<n;i++){

    /*updates for every step in X and Y*/
    double k1x=fx(VX[i],VY[i], c);
    double k1y=fy(VX[i],VY[i], c);
        
    double k2x=fx(VX[i]+0.5*h*k1x,VY[i]+0.5*h*k1y, c);
    double k2y=fy(VX[i]+0.5*h*k1x,VY[i]+0.5*h*k1y, c);
        
    double k3x=fx(VX[i]+0.5*h*k2x,VY[i]+0.5*h*k2y, c);
    double k3y=fy(VX[i]+0.5*h*k2x,VY[i]+0.5*h*k2y, c);
        
    double k4x=fx(VX[i]+h*k3x,VY[i]+h*k3y, c);
    double k4y=fy(VX[i]+h*k3x,VY[i]+h*k3y, c);
        
    double k5x=VX[i];
    double k6x=(VX[i]+0.5*h*k1x);
    double k7x=(VX[i]+0.5*h*k2x);
    double k8x=(VX[i]+h*k3x);

    double k5y=VY[i];
    double k6y=(VY[i]+0.5*h*k1y);
    double k7y=(VY[i]+0.5*h*k2y);
    double k8y=(VY[i]+h*k3y);
    /*We calculate the next steps*/
    X[i+1]=X[i]+h*(k5x+2*k6x+2*k7x+k8x)/6;
    VX[i+1]=VX[i]+h*(k1x+2*k2x+2*k3x+k4x)/6;
    Y[i+1]=Y[i]+h*(k5y+2*k6y+2*k7y+k8y)/6;
    VY[i+1]=VY[i]+h*(k1y+2*k2y+2*k3y+k4y)/6;
    
    std::cout<<X[i]<<" "<<Y[i]<<std::endl;
    }
}

double fx(double vx, double vy, float c){
    return -c*pow(vx,1)*vx/sqrt((vx*vx)+(vy*vy));
}
double fy(double vx, double vy, float c){
    return -9.8-c*pow(vy,1)*vy/sqrt((vx*vx)+(vy*vy));
}
