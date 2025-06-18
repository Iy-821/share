#include <stdio.h>
#define N 36000 //[s]

double glu[N+1];
double g6p[N+1];
double gluhk[N+1];
double hkfree[N+1];
double atp[N+1];
double hkatp[N+1];
double hkgluatp[N+1];
double adp[N+1];

double dglu[N+1];
double dgluhk[N+1];
double dhkfree[N+1];
double datp[N+1];
double dhkatp[N+1];
double dhkgluatp[N+1];
double dadp[N+1];
double dg6p[N+1];

double dt=600.0/N;   //[min]
double k1=1.0;
double k2=0.5;
double k3=0.5;
double k4=1.0;
double k5=0.1;
double hktot=0.1;

double fglu(double glu,double hkfree,double hkatp,double gluhk,double hkgluatp){
    double q1=k1*glu*hkfree;
    double q11=k1*glu*hkatp;
    return (-q1-q11+(k2*gluhk)+(k2*hkgluatp));
}

double fgluhk(double glu,double hkfree,double gluhk,double atp,double hkgluatp){
    double q1=k1*glu*hkfree;
    double q2=k2*gluhk;
    double q31=k3*atp*gluhk;
    double q41=k4*hkgluatp;
    return (q1-q2-q31+q41);
}

double fhkfree(double glu,double hkfree,double gluhk,double atp,double hkatp,double hkgluatp){
    double q1=k1*glu*hkfree;
    double q2=k2*gluhk;
    double q3=k3*atp*hkfree;
    double q4=k4*hkatp;
    double q5=k5*hkgluatp;
    return (-q1+q2-q3+q4+q5);
}

double fatp(double atp,double hkfree,double gluhk,double hkatp,double hkgluatp){
    double q3=k3*atp*hkfree;
    double q31=k3*atp*gluhk;
    return (-q3-q31+(k4*hkatp)+(k4*hkgluatp));
}

double fhkatp(double atp,double hkfree,double hkatp,double glu,double hkgluatp){
    double q3=k3*atp*hkfree;
    double q4=k4*hkatp;
    double q11=k1*glu*hkatp;
    double q21=k2*hkgluatp;
    return (q3-q4-q11+q21);
}

double fhkgluatp(double atp,double hkfree,double hkatp,double glu,double hkgluatp,double gluhk){
    double q31=k3*atp*gluhk;
    double q41=k4*hkgluatp;
    double q11=k1*glu*hkatp;
    double q21=k2*hkgluatp;
    double q5=k5*hkgluatp;
    return (q31-q41+q11-q21-q5);
}

double fg6p(double hkgluatp){
    double q5=k5*hkgluatp;
    return q5;
}

double fadp(double hkgluatp){
    double q5=k5*hkgluatp;
    return q5;
}

int main(void){
    glu[0]=1.0;
    atp[0]=0.5;
    gluhk[0]=0.0;
    hkatp[0]=0.0;
    hkgluatp[0]=0.0;
    g6p[0]=0.0;
    adp[0]=0.0;

    printf("%lf %lf %lf\n",dt*0,glu[0],g6p[0]);

    for(int i=0;i<N;i++){
        hkfree[i]=hktot-gluhk[i]-hkatp[i]-hkgluatp[i]; //hkfreeの濃度計算

        dglu[i]=fglu(glu[i],hkfree[i],hkatp[i],gluhk[i],hkgluatp[i]);
        dgluhk[i]=fgluhk(glu[i],hkfree[i],gluhk[i],atp[i],hkgluatp[i]);
        dhkfree[i]=fhkfree(glu[i],hkfree[i],gluhk[i],atp[i],hkatp[i],hkgluatp[i]);
        datp[i]=fatp(atp[i],hkfree[i],gluhk[i],hkatp[i],hkgluatp[i]);
        dhkatp[i]=fhkatp(atp[i],hkfree[i],hkatp[i],glu[i],hkgluatp[i]);
        dhkgluatp[i]=fhkgluatp(atp[i],hkfree[i],hkatp[i],glu[i],hkgluatp[i],gluhk[i]);
        dg6p[i]=fg6p(hkgluatp[i]);
        dadp[i]=fadp(hkgluatp[i]);

        glu[i+1]=glu[i]+dglu[i]*dt;
        gluhk[i+1]=gluhk[i]+dgluhk[i]*dt;
        hkfree[i+1]=hkfree[i]+dhkfree[i]*dt;
        atp[i+1]=atp[i]+datp[i]*dt;
        hkatp[i+1]=hkatp[i]+dhkatp[i]*dt;
        hkgluatp[i+1]=hkgluatp[i]+dhkgluatp[i]*dt;
        g6p[i+1]=g6p[i]+dg6p[i]*dt;
        adp[i+1]=adp[i]+dadp[i]*dt;

        printf("%lf %lf %lf\n",dt*(i+1),glu[i+1],g6p[i+1]);
    }

    return 0;
}