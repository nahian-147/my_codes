def mul1(a,b):
    mul = ''
    carry = 0
    for n in a[::-1]:
        p = int(n)*int(b) + carry
        mul += str((p)%10)
        carry = int(p/10)

    mul += str(carry)
    return mul[::-1]

def add(a,b):
    s = len(a)-len(b)
    
    if(s>=0):
        t = b[::-1]
        for _ in range(s):
            t += '0'
        b = t[::-1]
    else:
        t = a[::-1]
        for _ in range(-s):
            t += '0'
        a = t[::-1]

    sum = ''
    carry = 0
    k = len(a)-1
    while(not k < 0):
        v = int(a[k])+int(b[k])+carry
        sum += str(v%10)
        carry = int(v/10)
        k -= 1

    sum += str(carry)

    return sum[::-1]

a = input("a ? :")
b = input("b ? :")

M = []
z = ''
brev = b[::-1]
for k in brev:
    M.append(mul1(a,k)+z)
    z += '0'

sm = '0'
for num in M:
    sm = add(sm,num)

print(sm)
print(len(sm))
