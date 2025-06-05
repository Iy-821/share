#include <stdio.h>
#define N 3000

double f(double a,double b){
    double k=1.0;
    return a*b*k;
}


int main(void){
    double c[N+1];
    double a[N+1];
    double b[N+1];
    double dcdt[N+1];
    double dt=1/600.0;

    a[0]=1.0;
    b[0]=1.0;
    c[0]=0.0;


    printf("%lf %lf %lf %lf\n",dt*0,c[0],a[0],b[0]);

    for(int i=0;i<N;i++){
        dcdt[i]=f(a[i],b[i]);
        c[i+1]=c[i]+dcdt[i]*dt;
        a[i+1]=a[i]-dcdt[i]*dt;
        b[i+1]=b[i]-dcdt[i]*dt;
        printf("%lf %lf %lf %lf\n",dt*(i+1),c[i+1],a[i+1],b[i+1]);
    }

    return 0;
}