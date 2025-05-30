#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *fp;
    char c,gene[1002]={0};
    int num=0,count=0;
    double p;

    if((fp=fopen(argv[1],"r"))==NULL){
        printf("ファイルを開けません。\n");
        return -1;
    }

    while(fscanf(fp,"%c",&c)!=EOF){
        gene[num]=c;
        num++;
    }

    for(int k=0;k<=990;k++){
        count=0;
        for(int i=0;i<10;i++){
            if((gene[k+i]=='c')||(gene[k+i]=='g')){
                count++;
            }
        }
        p=count*10;
        printf("%dから%dまでに含まれるGC含有率は%.2f%%です。\n",k+1,k+10,p);
    }

    return 0;
}