i = input().split()
N,Q = int(i[0]),int(i[1])

AI = input().split()
ai = []
for n in AI:
    ai.append(int(n))

QI = input().split()
qi = []
for n in QI:
    qi.append(int(n))

for q in qi:
    ai_aux = ai.copy()
    count = 0
    p = 0
    while(p<len(ai_aux)-1):
        if q in ai_aux:
            count += 1
            i = ai_aux.index(q)
            ai_aux[i] = 0
        elif (q-ai_aux[p]) in ai_aux:
            count += 1
            i1 = ai_aux.index(q-ai_aux[p])
            ai_aux[i1] = 0
            i2 = ai_aux.index(ai_aux[p])
            ai_aux[i2] = 0
            p += 1
        p += 1
    print(count)
