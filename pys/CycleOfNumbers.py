n = int(input())

def f(n):
    nsList = list(str(n))
    nvList = []
    for num in nsList:
        nvList.append(int(num))
    sm = 0
    for k in nvList:
        sm += k*k
    return sm

L = [n]

for k in range(9999):
    n = f(n)
    if n == 1:
        print('NO CYCLE')
        break
    else:
        if n in L:
            if n == L[0]:
                print('FULL CYCLE')
                break
            else:
                print('PARTIAL CYCLE')
                break
    L.append(n)
   
