import sys

memo = {1:1}

def findLen(n):
    if n in memo:
        return memo[n]
    elif n % 2 == 0:
        memo[n] = 1 + findLen(int(n/2))
    else:
        memo[n] = 1 + findLen(3*n+1)
    return memo[n]


while True:
    try:
        ij = sys.stdin.read()
    except:
        break
    macs = 1
    if not len(ij) == 0:
        ij = ij.split(" ")
        i,j = int(ij[0]),int(ij[1])
        for _ in range(min(i,j),max(i,j)+1):
            L = findLen(_)
            if L > macs:
                macs = L
        print(i,j,macs)

print()