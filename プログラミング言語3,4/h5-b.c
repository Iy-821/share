#include <stdio.h>
int data[100000];
int main(int argc, char *argv[]){
    FILE *fp;
    int n,temp,max,min;
    long long int sum;
    double ave,v1,v;
    int top=0;
    if((fp=fopen(argv[1],"r"))==NULL){
        printf("ファイルを開けません\n");
        return -1;
    }
    sum=0;
    while(fscanf(fp,"%d",&n)!=EOF){
        data[top]=n;
        sum+=data[top];
        top++;
    }

    max=data[0];
    min=data[0];

    for(int i=1;i<top;i++){
        if(max<data[i]){
            max=data[i];
        }
        if(min>data[i]){
            min=data[i];
        }
    }

    ave=(double)sum/top;
    v=0;

    for(int i=0;i<top;i++){
        v1=data[i]-ave;
        v+=v1*v1;
    }
    v/=(double)top;

    printf("最大値:%d,最小値:%d,合計値:%lld,平均値:%.1f,分散:%.1f\n",max,min,sum,ave,v);

    return 0;
}