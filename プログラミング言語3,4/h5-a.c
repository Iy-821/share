#include <stdio.h>
int main(void){
    int x[10];
    for(int i=0;i<10;i++){
        printf("x[%d]:",i); scanf("%d",&x[i]);
    }

    for(int i=0;i<10;i++){
        if(x[i]%2==0){
            for(int k=i;k<10;k++){
                printf("%d ",x[k]);
            }
            printf("\n");
        }
    }

    return 0;
}