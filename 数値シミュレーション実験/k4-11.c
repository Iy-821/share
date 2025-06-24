#include <stdio.h>
#define N 300000

double dt = 0.001;
double t=0.0;
double M, P1, P2;
double Vm=1.0;
double Vp=0.5;
double kp1=10.0;
double kp2=0.03;
double kp3=0.1;
double km=0.1;
double P=0.1;
double Jp=0.05;
double ka=2000.0;
double kd=10.0;
double r=2.0;
double dm, dp1, dp2;

int main(void){

    for (int i=0;i<N;i++){
        dm=(Vm/(1+(P2/P)*(P2/P)))-km*M;
        dp1=Vp*M-((kp1*P1)/(Jp+P1+r*P2))-kp3*P1-2.0*ka*P1*P1+2.0*kd*P2;
        dp2=ka*(P1*P1)-kd*P2-((kp2*P2)/(Jp+P1+r*P2))-kp3*P2;
        M+=dm*dt;
        P1+=dp1*dt;
        P2+=dp2*dt;
        printf("%lf %lf %lf %lf\n", dt*i,M,P1,P2);
    }

    return 0;
}