#include <stdio.h>

int main(void){
    double x[4]={1.2,2.1,4.2,8.5};
    int i;
    double s=0.0;

    for(int i=0;i<4;i++){
        s+=x[i]*x[i];
    }

    printf("和:%lf",s);
    return 0;
}