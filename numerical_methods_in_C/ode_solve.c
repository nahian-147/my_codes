#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f1_xy(double t, double v){
    double g = 9.81;
    double c_drag = 0.225;
    double m = 90;
    return g - (c_drag/m)*v*v;
}

double f2_xy(double t, double y, double (*f)(double,double), double h){
    return (f(t+h,y)-f(t-h,y) + (f(t,y+h)-f(t,y-h))) / (2*h);
}

double f3_xy(double t, double y, double (*f)(double,double), double h){
    return (f(t+2*h,y) -2*f(t,y) +f(t-2*h,y) + (f(t,y+2*h) -2*f(t,y) +f(t,y-2*h))) / (4*h*h);
}

double ode_solve(double y0, double t0, double h, double tf){
    double t = t0, y = y0;

    while(t<=tf){
        y = y + h*f1_xy(t,y) + h*h*f2_xy(t,y,&f1_xy,h)/2 + (h*h*h)*f3_xy(t,y,&f1_xy,h)/6;
        t += h;
    }

    return y;
}

int main(){

    double h = 0.001;

    double t0 = 0;
    double v0 = 0;
    double y0 = 1000;
    double y = y0;
    double v = v0;
    double t = t0;
    while (v <= 20){
        t = t + h;
        v = ode_solve(v0,t0,h,t);
        y = y - h*v;
        printf("v y t %2.15lf %2.15lf %2.15lf \n",v,y,t);
    }
    

    printf("v %2.15lf \n",v);

    return 0;
}
