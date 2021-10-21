def dfs(node,G):
    if not G[node]:
        print(node)
        return
    else:
        for n in G[node]:
            dfs(n,G)
        print(node)
        return
    

g = {'root':['a','b','c'],
     'a':['d','e'],
     'b':['f','g'],
     'c':['h'],
     'd':['i'],
     'e':['j'],
     'f':[],'g':[],'h':[],'i':[],'j':[]}

print(dfs('root',g))