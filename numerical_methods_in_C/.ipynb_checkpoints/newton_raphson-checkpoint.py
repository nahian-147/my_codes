import numpy as np

def d1f(f,x):
    dx = .00000000001
    return (f(x+dx)-f(x-dx))/(2*dx)

def newton_raphson_root_finder(f,x0,n):
    iteration = 0
    xn = x0
    for iteration in range(n+1):
        xn -= f(xn)/d1f(f,xn)
    return xn

def f(x):
    return np.power(x,2) - 2*x -1

print(newton_raphson_root_finder(f,-.25,4))