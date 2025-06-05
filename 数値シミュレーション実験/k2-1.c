#include <stdio.h>
#define N 3000

double f(double g){
    double k=-1.0;
    return k*g;
}


int main(void){
    double glu[N+1];
    double dgludt[N+1];
    double g6p[N+1];
    double dt=1/600.0;

    glu[0]=1.0;
    g6p[0]=0.0;

    printf("%lf %lf %lf\n",dt*0,glu[0],g6p[0]);

    for(int i=0;i<N;i++){
        dgludt[i]=f(glu[i]);
        glu[i+1]=glu[i]+dgludt[i]*dt;
        g6p[i+1]=-f(glu[i]);
        printf("%lf %lf %lf\n",dt*(i+1),glu[i+1],g6p[i+1]);
    }

    return 0;
}