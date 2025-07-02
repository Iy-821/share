#include <stdio.h>
#include <math.h>
#define N 100
#define PI 3.1415

double xa[N+1],xb[N+1],ya[N+1],yb[N+1];
double vxa[N+1],vxb[N+1],vya[N+1],vyb[N+1];
double dxadt[N+1],dxbdt[N+1],dyadt[N+1],dybdt[N+1],dvxadt[N+1];
double dvxbdt[N+1],dvyadt[N+1],dvybdt[N+1];
double dt,m,a_theta,b_theta,g,v0;

double fdxadt(){
    return (v0*cos(a_theta));
}

double fdyadt(double t){    //tの単位はs
    return (v0*sin(a_theta)-g*t);
}

double fdxbdt(){
    return (30.0*cos(b_theta));
}

double fdybdt(double t){
    return (30.0*sin(b_theta)-g*t);
}

double fdvxadt(){
    return 0;
}

double fdvyadt(){
    return -g;
}

double fdvxbdt(){
    return 0;
}

double fdvybdt(){
    return -g;
}

int main(void){
    xa[0]=0.0;
    ya[0]=0.0;
    xb[0]=20.0;
    yb[0]=0.0;
    vxa[0]=v0*cos(a_theta);
    vya[0]=v0*sin(a_theta);
    vxb[0]=v0*30.0*cos(b_theta);
    vyb[0]=30*sin(b_theta);
    m=0.2;
    a_theta=105.0*(PI/180.0);
    b_theta=35.0*(PI/180.0);
    g=9.8;
    v0=17.8;
    dt=1.0/N;

    printf("%lf %lf %lf %lf %lf\n",dt*0,xa[0],ya[0],xb[0],yb[0]);

    for(int i=0;i<N;i++){
        dxadt[i]=fdxadt();
        dyadt[i]=fdyadt(i*dt);
        dxbdt[i]=fdxbdt();
        dybdt[i]=fdybdt(i*dt);
        dvxadt[i]=fdvxadt();
        dvyadt[i]=fdvyadt();
        dvxbdt[i]=fdvxbdt();
        dvybdt[i]=fdvybdt();

        xa[i+1]=xa[i]+dxadt[i]*dt;
        xb[i+1]=xb[i]-dxbdt[i]*dt;
        ya[i+1]=ya[i]+dyadt[i]*dt;
        yb[i+1]=yb[i]+dybdt[i]*dt;
        vxa[i+1]=vxa[i]+dvxadt[i]*dt;
        vxb[i+1]=vxb[i]+dvxbdt[i]*dt;
        vya[i+1]=vya[i]+dvyadt[i]*dt;
        vyb[i+1]=vyb[i]+dvybdt[i]*dt;

        printf("%lf %lf %lf %lf %lf\n",dt*(i+1),xa[i+1],ya[i+1],xb[i+1],yb[i+1]);
    }

    return 0;

}