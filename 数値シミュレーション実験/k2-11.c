#include <stdio.h>
#define N 3000

double f(double s1,double s2){
    double kms1=0.75;
    double kms2=0.25;
    double vmax=0.02*60;
    double k1=(vmax*s1*s2)/(kms1*kms2);
    double k2=1.0+(s1/kms1)+(s2/kms2)+((s1*s2)/(kms1*kms2));
    return k1/k2;
}

int main(void){
    double s1[N+1];
    double s2[N+2];
    double p[N+1];
    double dpdt[N+1];
    double dt=1/600.0;

    s1[0]=1.0;
    s2[0]=1.0;
    p[0]=0.0;
    printf("%lf %lf %lf\n",dt*0,p[0],s1[0],s2[0]);

    for(int i=0;i<N;i++){
        dpdt[i]=f(s1[i],s2[i]);
        p[i+1]=p[i]+dpdt[i]*dt;
        s1[i+1]=s1[i]-dpdt[i]*dt;
        s2[i+1]=s2[i]-dpdt[i]*dt;
        printf("%lf %lf %lf\n",dt*(i+1),p[i+1],s1[i+1],s2[i+1]);
    }

    return 0;
}