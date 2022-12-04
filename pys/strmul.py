# a = input("Enter a number, a = ")
# b = input("Enter another number, b = ")

a="23108814760092"
b="55183904456427981"
mul = ''
carry = 0
for n in a[::-1]:
    print(n,mul)
    p = int(n)*int(b) + carry
    mul += str((p)%10)
    carry = int(p/10)

if carry != 0:
    mul += str(carry)[::-1]

mul = mul[::-1]
        
while mul[0] == '0' and len(mul) > 1:
    mul = mul[1:]

print(mul)
