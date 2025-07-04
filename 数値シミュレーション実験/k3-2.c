#include <stdio.h>
#define N 36000 //36000回実行

double glu[N+1];
double g6p[N+1];
double gluhk[N+1];
double hkfree[N+1];

double dglu[N+1];
double dgluhk[N+1];
double dg6p[N+1];

double dt=600.0/N;   //1回1sで36000回で600分

double fglu(double k1,double glu,double hkfree,double gluhk,double k2){
    double q1=k1*glu*hkfree;
    double q2=k2*gluhk;
    return (-q1+q2);
}

double fgluhk(double k1,double glu,double hkfree,double gluhk,double k2,double k3){
    double q1=k1*glu*hkfree;
    double q2=k2*gluhk;
    double q3=c
    return (q1-q2-q3);
}

double fg6p(double k3,double gluhk){
    double q3=k3*gluhk;
    return q3;

}

int main(void){
    glu[0]=1.0;
    gluhk[0]=0.0;
    g6p[0]=0.0;
    double k1=1.0;
    double k2=1.0;
    double k3=0.1;
    double hktotal=0.1;

    printf("%lf %lf %lf\n",dt*0,glu[0],g6p[0]);

    for(int i=0;i<N;i++){
        hkfree[i]=hktotal-gluhk[i]; //hkfreeの濃度計算
        dglu[i]=fglu(k1,glu[i],hkfree[i],gluhk[i],k2);
        dgluhk[i]=fgluhk(k1,glu[i],hkfree[i],gluhk[i],k2,k3);
        dg6p[i]=fg6p(k3,gluhk[i]);

        glu[i+1]=glu[i]+dglu[i]*dt;
        gluhk[i+1]=gluhk[i]+dgluhk[i]*dt;
        g6p[i+1]=g6p[i]+dg6p[i]*dt;

        printf("%lf %lf %lf\n",dt*(i+1),glu[i+1],g6p[i+1]);
    }

    return 0;
}