def isPrime(n):
    if n < 2:
        return False
    elif n in [2,3,5,7,11]:
        return True
    else:
        k = 3
        while(k*k <= n):
            if(n%k == 0):
                return False
            k += 2
        return True

N = int(input())
if N == 1:
    print(2)
else:
    num = 3
    L = []
    while(N-1>len(L)):
        if(isPrime(num)):
            L.append(num)
        num += 2

    print(L[N-1-1])
