#include <stdio.h>
#define N 3001

int main(void){
    
    double c[N+1];
    double t[N+1];
    for(int i=0;i<N;i++){
        t[i]=i/600.0;
        c[i]=0.1*t[i];
        printf("%lf %lf\n",t[i],c[i]);
    }

    return 0;
}