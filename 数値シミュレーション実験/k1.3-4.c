#include <stdio.h>
#include <math.h>
#define N 100
#define PI 3.1415

double x[N+1],y[N+1],vx[N+1],vy[N+1],dxdt[N+1],dydt[N+1],dvxdt[N+1],dvydt[N+1];
double dt,h,g,theta;

double fdxdt(){
    return (20.0*cos(theta));
}

double fdydt(double t){
    return (20.0*sin(theta)-g*t);
}

double fdvxdt(){
    return 0;
}

double fdvydt(){
    return -g;
}

int main(void){
    dt=5.7/N;
    theta=30.0*(PI/180.0);
    h=100.0;
    g=9.8;
    x[0]=0.0;
    y[0]=h;
    vx[0]=20.0*cos(theta);
    vy[0]=20.0*sin(theta);

    printf("%lf %lf %lf\n",dt*0,x[0],y[0]);

    for(int i=0;i<N;i++){
        dxdt[i]=fdxdt();
        dydt[i]=fdydt(i*dt);
        dvxdt[i]=fdvxdt();
        dvydt[i]=fdvydt();

        x[i+1]=x[i]+dxdt[i]*dt;
        y[i+1]=y[i]+dydt[i]*dt;
        vx[i+1]=vx[i]+dvxdt[i]*dt;
        vy[i+1]=vy[i]+dvydt[i]*dt;

        printf("%lf %lf %lf\n",dt*(i+1),x[i+1],y[i+1]);
    }

    return 0;
}