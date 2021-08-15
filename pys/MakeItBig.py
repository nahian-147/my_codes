N = int(input())
Nn = []
for _ in range(N):
    Nn.append(input())
for n in Nn:
    nl = list(n)
    nl.sort()
    num = ''
    nl = nl[::-1]
    for k in nl:
        num += k
    print(num)

