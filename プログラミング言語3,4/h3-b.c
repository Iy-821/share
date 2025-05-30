#include <stdio.h>
#define MAX 5

int ring_Q[MAX];
int num,rap;    //rap週

void Qinit(){
    num=0;
    rap==0;
}

void enter(int inQ){
    if(num==MAX-1){
        num=0;
        rap++;
    }
    ring_Q[num]=inQ;
    num++;
}

int getq(){
    if(num==0&&rap>0){
        num=MAX-1;
        rap--;
    }
    int val;
    val=ring_Q[0];
    if(rap>0){  //データで全部埋まってる
        for(int i=0;i<MAX-1;i++){
            ring_Q[i]=ring_Q[i+1];
        }
    }
    else if(rap==0){    //rap=0のとき埋まってる場所は限られる
        for()
    }

}

int main(void){

}
