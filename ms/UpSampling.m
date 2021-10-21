clear all;
close all;

f = 0.05;
n = 0:39;
x = sin(2*pi*f*n);
subplot(211),stem(n,x),xlabel('index'),title('The original signal');

L = 3;
k = n(1);
id = 1;

for i = 1:L*length(n)
    if(~mod(k,L))
        y(i) = x(id);
        id = id + 1;
    else
        y(i) = 0;
    end
    k = k + 1;
end

subplot(212),stem(y),xlabel('index'),title('UpSampled Signal factor = 3');