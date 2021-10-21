h1=[-1 0 3 4]; 
h1_id=[-2:1]; 

h2 = [2 3 0 7 1]
h2_id = [-1:3]

x=[2 3 5 -2]; 

x_id=[0:3];

idmin1 = h1_id(1) + x_id(1);

idmax1 = h1_id(end) + x_id(end);

idy1 = idmin1:idmax1;

y1 =  conv(x,h1);
y1id = 0:length(y1);

idmin2 = h2_id(1) + y1id(1);
idmax2 = h2_id(end) + y1id(end);

idy = idmin2:idmax2;
y = conv(y1,h2)

stem(idy,y)
