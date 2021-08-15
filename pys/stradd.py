a = input("Enter a = ")
b = input("Enter b = ")

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

print(sum[::-1])