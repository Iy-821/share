#include <stdio.h>
int data[100000];
int main(void){
    int x,n;
    int top=0;
    printf("数字を入力してください:");  scanf("%d",&x);

    if(x==1){
        FILE *fp;
        if((fp=fopen("random10000.txt","r"))==NULL){
            printf("ファイルを開けません\n");
            return -1;
        }
        while(fscanf(fp,"%d",&n)!=EOF){
            data[top]=n;
            top++;
        }

        for(int i=0;i<10;i++){
            printf("%d:%d\n",9991+i,data[9990+i]);
        }
    }else if(x==2){
        FILE *fp;
        if((fp=fopen("random100000.txt","r"))==NULL){
            printf("ファイルを開けません\n");
            return -1;
        }
        while(fscanf(fp,"%d",&n)!=EOF){
            data[top]=n;
            top++;
        }
        for(int i=0;i<10;i++){
            printf("%d:%d\n",99991+i,data[99990+i]);
        }
    }

    return 0;
}