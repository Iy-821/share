#include <stdio.h>
#define N 1000
struct cell{
    char data;
    int next;
};
struct cell celldata[N];
int first,top;

void init(){
    first=0;
    top=0;
}

void list_init(){
    celldata[N-1].data='Z';
    celldata[N-1].next=-1;
}

void printall(){
    int now=first;
    while(now!=-1){
        printf("%c\n",celldata[now].data);
        now=celldata[now].next;
    }
}

int main(void){
    init();
    list_init();

    for(;top<N;top++){
        celldata[top].data='A'+(top%26);
        celldata[top].next=top+1;
        if(top==N-1){
            celldata[top].next=-1;
        }
    }

    printall();
    return 0;
}