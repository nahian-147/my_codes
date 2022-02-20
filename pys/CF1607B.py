t = int(input())
Q = []
for _ in range(t):
    Q.append(input())

def final_pos(x0,n):
    pos = x0
    d = 1
    for _ in range(n):
        if(pos % 2 == 0):
            pos -= d
        else:
            pos += d
        d += 1
    return pos

def final_pos_formula(x0,n):
    if n % 2 == 0:
        S = 0
    else:
        S = int((n+1)/2)
    if x0 % 2 == 0:
        pos = x0 - S
    else:
        pos = x0 + S
    return pos
for _ in Q:
    print(final_pos_formula(int(_.split(" ")[0]), int(_.split(" ")[1])))