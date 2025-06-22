#include <stdio.h>
#define N 1000
int main(void){
    double x[N+1],y[N+1];
    double dxdt[N],dydt[N];
    double dt=0.001;

    x[0]=0.0;
    dxdt[0]=0.0;
    y[0]=0.0;
    printf("%lf %lf\n",dt*0,x[0]);

    for(int i=0;i<N;i++){
        dxdt[i+1]=y[i];
        dydt[i+1]=(-0.2*x[i]*x[i]+3.0*x[i]-4.0)/2.0;

        x[i+1]=x[i]+dxdt[i]*dt;
        y[i+1]=y[i]+dydt[i]*dt;
        
        printf("%lf %lf\n",dt*(i+1),x[i+1]);
    }

    return 0;
}