s = "aspacec"

wrds = {"as","spa","c","ce","sp","pa","ace"}

memo = {}
auxmemo = {}
for _ in range(1,len(s)+1):
    auxmemo[_] = []

def maximizer(s):
    if len(s) in memo:
        # auxmemo[len(s)].append(s)
        return memo[len(s)]
    elif len(s) == 1:
        if s in wrds:
            # auxmemo[1].append(s)
            memo[1] = 1
            return 1
        else:
            memo[1] = 0
            return 0
    else:
        for _ in range(1,len(s)):
            if s[-_:] in wrds:
                if len(s) in memo:
                    memo[len(s)] = max(maximizer(s[:len(s)-_]) + 1,memo[len(s)])
                    print(s[:len(s)-_],s[-_:])
                    # auxmemo[len(s)-_].append(s[-_:])
                else:
                    memo[len(s)] = maximizer(s[:len(s)-_]) + 1
                    print(s[:len(s)-_],s[-_:])
                    # auxmemo[len(s)-_].append(s[-_:])
            else:
                if len(s) in memo:
                    memo[len(s)] = max(maximizer(s[:len(s)-_]),memo[len(s)])
                    print(s[:len(s)-_],s[-_:])
                else:
                    memo[len(s)] = maximizer(s[:len(s)-_])
                    print(s[:len(s)-_],s[-_:])
    return memo[len(s)]

print(maximizer(s))
print(memo)
print(auxmemo)