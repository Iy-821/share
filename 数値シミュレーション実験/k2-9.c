#include <stdio.h>
#define N 3000

double f(double s){
    double km=0.75;
    double vmax=0.02;
    double sn;
    double kmn=km*km*km;
    sn=s*s*s;
    return (vmax*sn/(kmn+sn));
}

int main(void){
    double s[N+1];
    double p[N+1];
    double dpdt[N+1];
    double dt=1/600.0;

    s[0]=1.0;
    p[0]=0.0;


    printf("%lf %lf %lf\n",dt*0,p[0],s[0]);

    for(int i=0;i<N;i++){
        dpdt[i]=f(s[i]);
        p[i+1]=p[i]+dpdt[i]*dt;
        s[i+1]=s[i]-dpdt[i]*dt;
        printf("%lf %lf %lf\n",dt*(i+1),p[i+1],s[i+1]);
    }

    return 0;
}