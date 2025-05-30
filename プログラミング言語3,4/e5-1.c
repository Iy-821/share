#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *fp;
    char c,gene[1002]={0};
    int num=0,count=0;
    int x;
    double p;

    if((fp=fopen(argv[1],"r"))==NULL){
        printf("ファイルを開けません。\n");
        return -1;
    }

    while(fscanf(fp,"%c",&c)!=EOF){
        gene[num]=c;
        num++;
    }

    printf("何文字目から探しますか："); scanf("%d",&x);
    
    for(int i=0;i<10;i++){
        if((gene[x+i-1]=='c')||(gene[x+i-1]=='g')){
            count++;
        }
    }
    p=count*10;

    printf("%dから%dまでに含まれるGC含有率は%.1f%%です。\n",x,x+9,p);

    return 0;
}