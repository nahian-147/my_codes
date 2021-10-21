a = input("Enter a number, a = ")
b = input("Enter another number, b = ")
mul = ''
carry = 0
for n in a[::-1]:
    p = int(n)*int(b) + carry
    mul += str((p)%10)
    carry = int(p/10)

mul += str(carry)

print(mul[::-1])
