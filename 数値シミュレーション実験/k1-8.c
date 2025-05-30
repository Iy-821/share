#include <stdio.h>
#define N 3000
double f(double t){
    return 1.0*t*t;
}

int main(void){
    double c[N+1];
    double dxdc[N+1];
    double t[N+1];
    double dt=1/600.0;  

    c[0]=0.0;
    printf("%lf %lf\n",dt*0,c[0]);

    for(int i=0;i<N;i++){
        t[i]=i/600.0;    
        dxdc[i]=f(t[i]);
        c[i+1]=c[i]+dxdc[i]*dt;
        printf("%lf %lf\n",dt*(i+1),c[i+1]);
    }

    return 0;
}