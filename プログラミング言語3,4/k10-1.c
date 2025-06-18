#include <stdio.h>
#define N 1000
struct cell{
    char data;
    int next;
};
struct cell celldata[N];
int first,top;

void init(){
    first=1;
    top=2;
}
void list_init(){
    celldata[0].data='Z';
    celldata[0].next=-1;
}

void printall(){
    int now=first;
    while(now!=-1){
        printf("%c ",celldata[now].data);
        now=celldata[now].next;
    }
}

void ins(int n,char x){
    int newdata;
    newdata=top;
    top++;
    celldata[newdata].data=x;
    celldata[newdata].next=celldata[n].next;
    celldata[n].next=newdata;
}

int main(void){
    init();
    list_init();
    char c[2];
    while(1){
        scanf("%s",c);
        if(c[0]=='Z'){
            printall();
        }else{
            ins(0,c[0]);
        }
    }
    return 0;
}