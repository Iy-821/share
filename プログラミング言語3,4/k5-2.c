#include <stdio.h>

int data[100000]={0};
int main(int argc, char *argv[]){
    FILE *fp;
    int n,temp;
    int top=0;
    if((fp=fopen(argv[1],"r"))==NULL){
        printf("ファイルを開けません\n");
        return -1;
    }
    while(fscanf(fp,"%d",&n)!=EOF){
        data[top]=n;
        top++;
    }               //10000ならtop=10000

    for(int i=0;i<top-1;i++){
        for(int k=i+1;k<top;k++){
            if(data[i]>data[k]){
                temp=data[i];
                data[i]=data[k];
                data[k]=temp;
            }
        }
    }

    for(int i=0;i<top;i++){
        printf("%d\n",data[i]);
    }

    /*
    for(int i=0;i<10;i++){          レポート用
        printf("%d\n",data[i]);
    }
    if(top==10000){
        for(int i=0;i<10;i++){
        printf("%d\n",data[9990+i]);
    }
    }else{
        for(int i=0;i<10;i++){
        printf("%d\n",data[99990+i]);
    }
    }
    */
    return 0;
}