function d1 = d1f(f,x)
    dx = 0.0000001;
    
    d1 = (f(x+dx) - f(x-dx)) / (2*dx);
end

