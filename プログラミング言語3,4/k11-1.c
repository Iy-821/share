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
    top=1;

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

void list(){
    int now=first;
    int i=1;
    now=celldata[now].next;
    while(now!=-1){
        printf("%d %d %c\n",i,now,celldata[now].data);
        now=celldata[now].next;
        i++;
    }
}

int main(void){
    init();
    list_init();
    char c[2];
    while(1){
        scanf("%s",c);
        if(c[0]=='Z'){
            printall();
        }else if(c[0]=='X'){
            list();
            
        }else{
            ins(0,c[0]);
            first++;
        }
    }
    return 0;
}