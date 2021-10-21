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


