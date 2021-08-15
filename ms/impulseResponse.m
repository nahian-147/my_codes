h=[1 2 1 -1]; 

h_id=[-1:2]; 

x=[1 2 3 3 3 3 1]; 

x_id=[0:6];

idmin = h_id(1) + x_id(1);

idmax = h_id(end) + x_id(end);


idy = idmin:idmax;

y =  conv(x,h);

stem(idy,y)
