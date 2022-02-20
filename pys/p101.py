n = int(input())
blocks = {}
for _ in range(n):
    blocks[_] = [_]


def reset(a):
    if blocks[a][0] < 0:
        lst = blocks[-blocks[a][0]][blocks[-blocks[a][0]].index(a):]
    else:
        lst = blocks[a]
    for _ in lst:
        if not _ == a:
            blocks[_] = [_]
            blocks[a].remove(_)


def onto_aux(a, b):
    if blocks[b][0] < 0:
        blocks[-blocks[b][0]].append(a)
        blocks[a] = [blocks[b][0]]
    else:
        blocks[b].append(a)
        blocks[a] = [-b]


def m_onto(a, b):
    reset(b)
    reset(a)
    onto_aux(a, b)


def m_over(a, b):
    reset(a)
    onto_aux(a, b)


def p_over(a, b):
    lst = blocks[-blocks[a][0]]
    blocks[b] += lst[lst.index(a):]
    blocks[-blocks[a][0]] = blocks[-blocks[a][0]][:lst.index(a)]
    blocks[a] = [-b]


def p_onto(a, b):
    reset(b)
    p_over(a, b)


def print_dict(d):
    for el in d:
        row = str(el) + ": "
        if not d[el][0] < 0:
            for _ in d[el]:
                row += str(_)
                if d[el].index(_) < len(d[el])-1:
                    row += " "
        print(row)


# m_onto(9, 1)
# m_over(8, 1)
# m_over(7, 1)
# m_over(6, 1)
# p_over(8, 6)
# p_over(8, 5)
# m_over(2, 1)
# m_over(4, 9)

Qrys = []
while True:
    qry = input()
    if qry == "quit":
        break
    qry = qry.split(" ")
    if len(qry) == 4:
        Qrys.append([qry[0] + qry[2], qry[1], qry[3]])

for qry in Qrys:
    if qry[0] == "moveonto":
        m_onto(int(qry[1]), int(qry[2]))
    elif qry[0] == "moveover":
        m_over(int(qry[1]), int(qry[2]))
    elif qry[0] == "pileonto":
        p_onto(int(qry[1]), int(qry[2]))
    elif qry[0] == "pileover":
        p_over(int(qry[1]), int(qry[2]))

print_dict(blocks)

# 10
# move 9 onto 1
# move 8 over 1
# move 7 over 1
# move 6 over 1
# pile 8 over 6
# pile 8 over 5
# move 2 over 1
# move 4 over 9
# quit