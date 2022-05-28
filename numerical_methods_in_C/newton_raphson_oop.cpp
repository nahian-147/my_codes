#include <stdio.h>
#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

double f(double x){
    return pow(x,2) -2*x - 1;
}

double d1f(function<double(double)> f,double x){
    double dx = 0.00000001;
    return (f(x+dx)-f(x-dx))/(2*dx);
}

double newton_raphson_root_finder(function<double(double)> f,double x0,int n){

    int iteration_count = 0;
    double xn = x0;
    while(iteration_count <= n){
        xn -= f(xn)/d1f(f,xn);
        iteration_count++;
    }
    return xn;
}

int main(){
    double x = -.25;
    cout << newton_raphson_root_finder(&f,x,4) << endl;
    return 0;
}