#include <stdio.h>
#define N 1000  //0.01刻みで0sから10sまで変化させるため

double f(double x){
    double dxdt=-x;
    return dxdt;
}

int main(void){
    double x[N+1];
    double dxdt[N+1];
    double dt=0.01;

    x[0]=1.0;   //初期
    printf("%lf %lf\n",dt*0,x[0]);  //座標
    
    for(int i=0;i<N;i++){
        dxdt[i]=f(x[i]);
        x[i+1]=x[i]+dxdt[i]*dt;
        printf("%lf %lf\n",dt*(i+1),x[i+1]);
    }

    return 0;
}