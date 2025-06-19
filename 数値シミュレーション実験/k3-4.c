#include <stdio.h>
#define N 36000

double s[N+1];
double p[N+1];
double dpdt[N+1];
double dt=600.0/N;

double vmax=0.1*0.1;
double km=(1.0+0.1)/1.0;

double f(double s){
    return ((vmax*s)/(km+s));
}

int main(void){
    s[0]=1.0;
    p[0]=0.0;
    printf("%lf %lf %lf\n",dt*0,s[0],p[0]);

    for(int i=0;i<N;i++){
        dpdt[i]=f(s[i]);
        p[i+1]=p[i]+dpdt[i]*dt;
        s[i+1]=s[i]-dpdt[i]*dt;
        printf("%lf %lf %lf\n",dt*(i+1),s[i],p[i]);
    }

    return 0;
}