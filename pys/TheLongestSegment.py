i = input()
k = int(i.split()[1])
H = input().split()
h = []
for n in H:
    h.append(int(n))

DL = []

def dist(a,b):
    if a>b:
        return a-b
    else:
        return b-a

diff = []

p = 0
l = len(h)-1
while(p < l):
    diff.append(dist(h[p],h[p+1]))
    p += 1

p = 0
l2 = len(diff)-1
L = 0
while(p<=l2):
    if diff[p] <= k:
        L += 1
        p += 1
        DL.append(L)
    else:
        L = 02 10 4 7
        p += 1
print(max(DL)+1)
