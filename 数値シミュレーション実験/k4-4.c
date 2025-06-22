#include <stdio.h>
#define N 700

double rx[N+1],ry[N+1];
double drxdt[N],drydt[N];


int main(void){
    double sx=3.0;
    double sy=6.0;
    double dt=0.1;
    rx[0]=1.0;
    ry[0]=2.0;
    drxdt[0]=sx-(rx[0]/10.0);
    drydt[0]=sy-(ry[0]/10.0);
    printf("%lf %lf %lf\n",dt*0,rx[0],ry[0]);

    for(int i=0;i<N;i++){
        drxdt[i+1]=sx-(rx[i]/10.0);
        drydt[i+1]=sy-(ry[i]/10.0);

        rx[i+1]=rx[i]+drxdt[i]*dt;
        ry[i+1]=ry[i]+drydt[i]*dt;

        printf("%lf %lf %lf\n",dt*(i+1),rx[i+1],ry[i+1]);
    }

    return 0;
}
