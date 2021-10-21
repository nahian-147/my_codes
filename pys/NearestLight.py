lights = [True for _ in range(5000000)]

Q = int(input())

queries = []

for _ in range(Q):
    queries.append(input().split())

for query in queries:
    if(query[0]=='1'):
        lights[int(query[1])] = False
    elif(query[0]=='2'):
        pos = int(query[1])
        dist = 0
        for dist in range(5000000-pos):
            if (lights[pos+dist] or lights[pos-dist]):
                print(dist)
                break
