import re
import numpy as np
import os


def f1_xy(y,t):
    return y*np.power(t,2) - 1.1*y

def f2_xy(y,t,f,h):
    return (f(y,t+h)-f(y,t-h) + (f(y+h,t)-f(y-h,t)))/ (2*h)

def f3_xy(y,t,f,h):
    return (f(y,t+2*h) -2*f(y,t) +f(y,t-h) + (f(y+2*h,t) -2*f(y,t) +f(y-2*h,t)))/ (4*h*h)


h = 0.000001

t0 = 0
y0 = 1

def ode_solve(y0,t0,h,tf):
    t = t0
    y = y0

    while(t<=tf):
        y = y + h*f1_xy(y,t) + h*h*f2_xy(y,t,f1_xy,h)/2 + (h**3)*f3_xy(y,t,f1_xy,h)/6
        t += h
    
    return y,t

# print(ode_solve(y0,t0,h,2))

os.system('./ode_solve')