#include <stdio.h>
#define N 1800 
double efree[N+1];
double etot;
double s[N+1];
double p[N+1];
double es[N+1];

double dsdt[N+1];
double desdt[N+1];
double dpdt[N+1];

double dt=30.0/N;  

double fs(double k1,double efree,double es,double s,double k2){
    double q1=k1*s*efree;
    double q2=k2*es;
    return (-q1+q2);
}

double fes(double k1,double s,double efree,double es,double k2,double k3){
    double q1=k1*s*efree;
    double q2=k2*es;
    double q3=k3*es;
    return (q1-q2-q3);
}

double fp(double k3,double es){
    double q3=k3*es;
    return q3;
}

int main(void){
    s[0]=4.0;
    es[0]=0.0;
    p[0]=0.0;
    
    double k1=10.8147;
    double k2=-10.3587;
    double k3=87.5;
    double etot=0.0000016;

    printf("%lf %lf %lf\n",dt*0,s[0],p[0]);

    for(int i=0;i<N;i++){
        efree[i]=etot-es[i]; //hkfreeの濃度計算
        dsdt[i]=fs(k1,efree[i],es[i],s[i],k2);
        desdt[i]=fes(k1,s[i],efree[i],es[i],k2,k3);
        dpdt[i]=fp(k3,es[i]);

        s[i+1]=s[i]+dsdt[i]*dt;
        es[i+1]=es[i]+desdt[i]*dt;
        p[i+1]=p[i]+dpdt[i]*dt;

        printf("%lf %lf %lf\n",dt*(i+1),s[i+1],p[i+1]);
    }

    return 0;
}