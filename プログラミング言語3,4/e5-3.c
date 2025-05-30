#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *fp;
    char c,gene[1002]={0};
    int num=0,count=0;
    double p;
    int x;

    if((fp=fopen(argv[1],"r"))==NULL){
        printf("ファイルを開けません。\n");
        return -1;
    }

    while(fscanf(fp,"%c",&c)!=EOF){
        gene[num]=c;
        num++;
    }
    printf("先頭から何文字を読み込みますか："); scanf("%d",&x);
    for(int k=0;k<=1000-x;k++){
        count=0;
        for(int i=0;i<x;i++){
            if((gene[k+i]=='c')||(gene[k+i]=='g')){
                count++;
            }
        }
        p=count*(100/x);
        printf("%dから%dまでに含まれるGC含有率は%.2f%%です。\n",k+1,k+x,p);
    }
    return 0;
}