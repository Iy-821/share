#include <stdio.h>
#include <math.h>
#define N 1000
#define PI 3.1415
double xa[N+1],xb[N+1],ya[N+1],yb[N+1];
double vxa[N+1],vxb[N+1],vya[N+1],vyb[N+1];
double dxbdt[N+1],dyadt[N+1],dybdt[N+1],dvxadt[N+1],dvxbdt[N+1],dvyadt[N+1],dvybdt[N+1];
double dt,m,a_theta,b_theta,g,v0;

double fdxadt(){
    return (v0*cos(a_theta));
}

double fdyadt(double t){    //tの単位はs
    return (v0*sin(a_theta)-g*t);
}

double fdxbdt(){

}

double fdybdt(){

}

double fdvxadt(){

}

double dvyadt(){

}

double dvxbdt(){

}

double fdvybdt(){
    
}

int main(void){
    xa[0]=0.0;
    ya[0]=0.0;
    xb[0]=20.0;
    yb[0]=0.0;
    m=0.2;
    a_theta=105.0*(PI/180.0);
    b_theta=35.0*(PI/180.0);
    g=9.8;
    v0=17.8

}
