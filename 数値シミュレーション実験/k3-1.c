#include <stdio.h>
#define N 25

int main(void){
    double a[N+1];
    double b[N+1];
    a[0]=1.0;
    b[0]=0.0;
    printf("%lf %lf\n",a[0],b[0]);

    for(int i=0;i<N;i++){
        a[i+1]=0.866*a[i]-0.500*b[i];
        b[i+1]=0.500*a[i]+0.866*b[i];
        printf("%lf %lf\n",a[i+1],b[i+1]);
    }

    return 0;
}