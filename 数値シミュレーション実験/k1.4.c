#include <stdio.h>
#include <math.h>
#define N 1000
#define PI 3.1415
double x[N+1],v[N+1],dvdt[N+1];
double dt,k,m;

double fdvdt(double x){
    return (-(k*x)/m);
}

int main(void){
    x[0]=0.2;
    dt=10.0/N;
    k=7.2;
    m=0.2;
    v[0]=0.0;

    printf("%lf %lf %lf\n",dt*0,x[0],v[0]);

    for(int i=0;i<N;i++){
        dvdt[i]=fdvdt(x[i]);

        x[i+1]=x[i]+v[i]*dt;
        v[i+1]=v[i]+dvdt[i]*dt;

        printf("%lf %lf %lf\n",dt*(i+1),x[i+1],v[i+1]);

    }
    return 0;
}