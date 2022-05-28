funtion root = newton_raphson(f,x0,n)
    xn = x0;

    for iteration = 0:n
        xn = xn - f(xn)/d1f(f,xn);
    end

    root = xn;
end