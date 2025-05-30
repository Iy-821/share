#include <stdio.h>
#define N 10
int main(void){
    double a[N+1];

    a[0]=0.0;
    printf("a[0]=%f\n",a[0]);

    for(int i=0;i<N;i++){
        a[i+1]=a[i]*0.5+0.5;
        printf("a[%d]=%lf\n",i+1,a[i+1]);
    }

    return 0;
}