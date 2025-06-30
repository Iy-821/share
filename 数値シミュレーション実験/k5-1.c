#include <stdio.h>
#define N 100

double vx[N+1];
double vy[N+1];
double x[N+1];
double y[N+1];
double dxdt[N+1];
double dydt[N+1];
double dvxdt[N+1];
double dvydt[N+1];
double dt=0.1;

int main(void){
    x[0]=0.0;
    y[0]=300.0;
    vx[0]=0.0;
    vy[0]=0.0;

    printf("%lf %lf %lf\n",dt*0,x[0],y[0]);

    for(int i=0;i<N;i++){
        dxdt[i]=vx[i];
        dydt[i]=vy[i];
        dvxdt[i]=0;
        dvydt[i]=-9.8;

        x[i+1]=x[i]+dxdt[i]*dt;
        y[i+1]=y[i]+dydt[i]*dt;
        vx[i+1]=vx[i]+dvxdt[i]*dt;
        vy[i+1]=vy[i]+dvydt[i]*dt;

        printf("%lf %lf %lf\n",dt*(i+1),x[i+1],y[i+1]);
    }

    return 0;
}