#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


void rk4(int n);
double fx(double velocidadx, double velocidady);
double fy(double velocidadx, double velocidady);

int main(){
    
    int n=500; /*Numero de iteracioens para el rk4*/
    rk4(n);
    
    return 0;
}

void rk4(int n){
    double h=0.01; /*Sensibilidad del paso del paso*/
    /*Inicializamos las velocidades y las posiciones */
    double *X=new double[n];
    double *Y=new double[n];
    double *VX=new double[n];
    double *VY=new double[n];   
    /*Condiciones iniciales*/   
    double x_ini=0.0;
    double vx_ini=10.0;
    X[0]=x_ini;
    VX[0]=vx_ini;
    
    double y_ini=0.0;
    double vy_ini=10.0;
    Y[0]=y_ini;
    VY[0]=vy_ini;
    for(int i=0;i<n;i++){
        
    /*Actualizamos los tamaños de los pasos para X y para Y*/
    double k1x=h*fx(VX[i],VY[i]); 
    double k1y=h*fy(VX[i],VY[i]);
        
    double k2x=h*fx(VX[i]+0.5*k1x,VY[i]+0.5*k1y);
    double k2y=h*fy(VX[i]+0.5*k1x,VY[i]+0.5*k1y);   
        
    double k3x=h*fx(VX[i]+0.5*k2x,VY[i]+0.5*k2y);
    double k3y=h*fy(VX[i]+0.5*k2x,VY[i]+0.5*k2y);   
        
    double k4x=h*fx(VX[i]+k3x,VY[i]+k3y);
    double k4y=h*fy(VX[i]+k3x,VY[i]+k3y);
        
    double k5x=h*VX[i];
    double k6x=h*(VX[i]+0.5*k1x);
    double k7x=h*(VX[i]+0.5*k2x);
    double k8x=h*(VX[i]+k3x);

    double k5y=h*VY[i];
    double k6y=h*(VY[i]+0.5*k1y);
    double k7y=h*(VY[i]+0.5*k2y);
    double k8y=h*(VY[i]+k3y);
    /*Añadimos los pasos siguientes*/
    X[i+1]=X[i]+(k5x+2*k6x+2*k7x+k8x)/6;
    VX[i+1]=VX[i]+(k1x+2*k2x+2*k3x+k4x)/6;    
    Y[i+1]=Y[i]+(k5y+2*k6y+2*k7y+k8y)/6;
    VY[i+1]=Y[i]+(k1y+2*k2y+2*k3y+k4y)/6;
    
    std::cout<<X[i]<<" "<<Y[i]<<std::endl;
    }
}

double fx(double velocidadx, double velocidady){
    return -0.7*(velocidadx*velocidadx)/sqrt((velocidadx*velocidadx)+(velocidady*velocidady));
}
double fy(double velocidadx, double velocidady){
    return -10+(-0.7*(velocidady*velocidady)/sqrt((velocidadx*velocidadx)+(velocidady*velocidady)));
}
