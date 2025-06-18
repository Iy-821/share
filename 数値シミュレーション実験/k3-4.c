#include <stdio.h>
#define N 36000
double s[N+1];
double p[N+1];

double dpdt[N+1];

double dt=6.0/N;   //[min]

double f(double s){
    double k1=1.0;
    double k2=1.0;
    double k3=0.1;
    double etot=0.1;
    double km=(k2+k3)/k1;
    double vmax=k3*etot;
    return ((vmax*s)/km+s);
    
}



int main(void){
    s[0]=1.0;
    p[0]=0.0;

    printf("%lf %lf %lf\n",dt*0,s[0],p[0]);

    for(int i=0;i<N;i++){
        dpdt[i]=f(s[i]);
        p[i+1]=p[i]+dpdt[i]*dt;
        s[i+1]=s[i]-dpdt[i]*dt;
        printf("%lf %lf %lf\n",dt*(i+1),s[i+1],p[i+1]);
    }

    return 0;
}