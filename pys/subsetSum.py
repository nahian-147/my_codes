s = [2, 14, 13, 17, 10, 21, 28]
memo = {0: True}


def if_contains_sum(st, n):
    if n == 0:
        return memo[0]
    elif n == st[0]:
        if not str(n)+str(st) in memo:
            memo[str(n)+str(st)] = True
        return memo[str(n)+str(st)]
    elif n > 0 and len(st) == 0:
        if not str(n)+str(st) in memo:
            memo[str(n)+str(st)] = False
        return memo[str(n)+str(st)]
    elif len(st) > 1:
        nn = st[0]
        memo[str(n)+str(st)] = if_contains_sum(st[1:], n) or if_contains_sum(st[1:], n - nn)
    else:
        if st[0] == n:
            if not str(n)+str(st) in memo:
                memo[str(n)+str(st)] = True
            return memo[str(n)+str(st)]
        else:
            if not str(n)+str(st) in memo:
                memo[str(n)+str(st)] = False
            return memo[str(n)+str(st)]
    return memo[str(n)+str(st)]


for _ in range(29, 106):
    print(_, s, if_contains_sum(s, _))
