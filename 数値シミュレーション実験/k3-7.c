#include <stdio.h>
#define N 90000

double s1[N+1]; //glu
double s2[N+1]; //atp
double p[N+1];  //g6p
double dpdt[N+1];
double dt=1500.0/N;

double kms1=0.5;
double kms2=2.0;
double vmax=0.01;

double fp(double s1,double s2){
    double a1=vmax*s1*s2;
    double a2=kms1*kms2;
    double a3=s1/kms1;
    double a4=s2/kms2;
    double a5=(s1*s2)/a2;
    return ((a1/a2)/(1+a3+a4+a5));
}

int main(void){
    s1[0]=1.0;
    s2[0]=0.5;
    p[0]=0.0;
    printf("%lf %lf %lf\n",dt*0,s1[0],p[0]);

    for(int i=0;i<N;i++){
        dpdt[i]=fp(s1[i],s2[i]);
        p[i+1]=p[i]+dpdt[i]*dt;
        s1[i+1]=s1[i]-dpdt[i]*dt;
        s2[i+1]=s2[i]-dpdt[i]*dt;
        printf("%lf %lf %lf\n",dt*(i+1),s1[i+1],p[i+1]);
    }

    return 0;
}