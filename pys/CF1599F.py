i1 = input()
n,q = i1.split(" ")[0],i1.split(" ")[1]

C = input().split(" ")
Q = []

C = [int(_) for _ in C]

def is_possibe_to_connect(l,r,d):
    l,r = l-1,r-1
    if((max(C[l],C[r])-min(C[l],C[r])) <= d):
        return True
    elif((max(C[l],C[r])-min(C[l],C[r])) % d == 0):
        return True
    else:
        return False

for k in range(int(q)):
    Q.append(input())

for p in Q:
    if(is_possibe_to_connect(int(p.split(" ")[0]), int(p.split(" ")[1]), int(p.split(" ")[2]))):
        print("Yes")
    else:
        print("No")
