#include <stdio.h>
#define N 1000

double f(double s){
    double km=0.5;
    double kmn=km*km*km;
    double vmax=1.0;
    double sn;
    sn=s*s*s;
    return (vmax*sn/(kmn+sn));
}

int main(void){
    double s[N+1];
    double v[N+1];
    double dt=1/100.0;


    printf("%lf %lf\n",s[0],v[0]);

    for(int i=0;i<N;i++){
        s[i+1]=s[i]+dt;
        v[i+1]=f(s[i+1]);
        printf("%lf %lf\n",s[i+1],v[i+1]);
    }

    return 0;
}