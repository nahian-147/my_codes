n = int(input())
for k in range(n):
    H = input()
    H = H.split()
    a,b,c = int(H[0]),int(H[1]),int(H[2])
    if(a+b>=c and b+c>=a and c+a>=b):
        print('Yes\n')
    else:
        print('No\n')

