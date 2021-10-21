clear all;
close all;

f = 0.05;
n = 0:39;
x = sin(2*pi*f*n);
subplot(211),stem(n,x),xlabel('index'),title('The original signal');

L = 2;
idx = n(1):L:n(end);

for i = 1:length(idx)
    k = find(n == idx(i));
    y(i) = x(k);
end

idy = idx/L;

subplot(212),stem(y),xlabel('index'),title('DownSampled Signal factor = 2');