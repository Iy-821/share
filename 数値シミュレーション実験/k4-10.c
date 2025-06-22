#include <stdio.h>
#define N 36000 //36000回実行

double efree[N+1];
double etot;
double s[N+1];
double p[N+1];
double es[N+1];



double dedt[N+1];
double desdt[N+1];
double dsdt[N+1];

double dt=600.0/N;   //1回1sで36000回で600分

double fe(double k1,double efree,double es,double s,double k2){
    double q1=k1*s*efree;
    double q2=k2*es;
    return (-q1+q2);
}

double fes(double k1,double s,double efree,double es,double k2,double k3){
    double q1=k1*s*efree;
    double q2=k2*es;
    double q3=*es;
    return (q1-q2-q3);
}

double fs(double k3,double s){
    double q3=k3*s;
    return q3;

}

int main(void){
    s[0]=4.0;
    es[0]=0.0;
    p[0]=0.0;
    double k1=21.0;
    double k2=62.293;
    double k3=87.5;
    double etot=0.0000016;

    printf("%lf %lf %lf\n",dt*0,s[0],p[0]);

    for(int i=0;i<N;i++){
        esfree[i]=etot-es[i]; //hkfreeの濃度計算
        ddte[i]=fe(k1,efree[i],es[i],s[0],k2);
        dgluhk[i]=fgluhk(k1,glu[i],hkfree[i],gluhk[i],k2,k3);
        dg6p[i]=fg6p(k3,gluhk[i]);

        glu[i+1]=glu[i]+dglu[i]*dt;
        gluhk[i+1]=gluhk[i]+dgluhk[i]*dt;
        g6p[i+1]=g6p[i]+dg6p[i]*dt;

        printf("%lf %lf %lf\n",dt*(i+1),glu[i+1],g6p[i+1]);
    }

    return 0;
}