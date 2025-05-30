#include <stdio.h>
#define N 3000
double f(){
    return 1.0;
}

int main(void){
    double c[N+1];
    double dxdc[N+1];
    double dt=1/600.0;

    c[0]=1.0;
    printf("%lf %lf\n",dt*0,c[0]);

    for(int i=0;i<N;i++){
        dxdc[i]=f();
        c[i+1]=c[i]+dxdc[i]*dt;
        printf("%lf %lf\n",dt*(i+1),c[i+1]);
    }

    return 0;
}