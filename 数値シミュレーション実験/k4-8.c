#include <stdio.h>
#define N 100000

double vx[N+1],vy[N+1];
double px[N+1],py[N+1];
double dpxdt[N+1],dpydt[N+1];
double dvxdt[N+1],dvydt[N+1];
double dt=0.001;

int main(void){
    px[0]=1.0;
    py[0]=0.0;
    dpxdt[0]=0.0;
    dpydt[0]=1.0;
    vx[0]=dpxdt[0];  //dpxdt[0]=vx[0]=0.0
    vy[0]=dpydt[0];

    printf("%lf %lf %lf\n",dt*0,px[0],py[0]);

    for(int i=0;i<N;i++){
        dpxdt[i]=vx[i];
        dvxdt[i]=-0.1*vx[i]-px[i];
        dpydt[i]=vy[i];
        dvydt[i]=-py[i];

        vx[i+1]=vx[i]+dvxdt[i]*dt;
        vy[i+1]=vy[i]+dvydt[i]*dt;
        px[i+1]=px[i]+dpxdt[i]*dt;
        py[i+1]=py[i]+dpydt[i]*dt;

        printf("%lf %lf %lf\n",dt*(i+1),px[i+1],py[i+1]);
    }

    return 0;
}