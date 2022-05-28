#include <stdio.h>
#include <math.h>

double func(double x){
    double g = 9.81;
    double v = 36;
    double t = 10;
    double c = 15;
    return v - (g*x/c)*(1-exp(-(c/x)*t)); 
}

double bisect(double l,double r){
    while(fabs(func(0.5*(l+r))) > 0.0001){
        if(func(0.5*(l+r))*func(l) > 0){
            l = 0.5*(l+r);
        }else if(func(0.5*(l+r))*func(r) > 0){
            r = 0.5*(l+r);
        }
    }
    return 0.5*(l+r);
    
}

int main(){
    double x;
    x = bisect(0,100);
    printf("%3.16lf\n",x);
    printf("%lf\n",func(x));
    return 0;
}