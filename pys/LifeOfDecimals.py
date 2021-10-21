from math import pi
p = str(pi)

T = int(input())
N = []
for _ in range(T):
    N.append(int(input()))
for n in N:
    print(p[n+1])

