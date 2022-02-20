class Graph:
	nodes = []
	edges = []
	adjdict = dict()

	def __init__(self,nds,edgs):
		self.nodes = nds
		self.edges = edgs
		for node in self.nodes:
			self.adjdict[node] = []
		for edge in self.edges:
			self.adjdict[edge[0]].append((edge[1],edge[2]))
			self.adjdict[edge[1]].append((edge[0],edge[2]))
	def add_node(self,n):
		self.nodes.append(n)
		self.adjdict[n] =  []

	def add_edge(self,nd1,nd2,w):
		self.edges.append((nd1,nd2,w))
		self.adjdict[nd1].append((nd2,w))
		self.adjdict[nd2].append((nd1,w))

	def show_dict(self):
		print(self.adjdict)

	def get_adjdict(self):
		return self.adjdict
	
	def isBipartite(self):
		nodes = self.nodes
		adj = dict()

		for node in self.adjdict:
			adj[node] = [ _[0] for _ in self.adjdict[node] ]

		p1 = set()
		p2 = set()
		

		for node in nodes:
			if not node in p2:
				if p1.isdisjoint(set(adj[node])):
					p1.add(node)
					for k in adj[node]:
						if k not in p1:
							if p2.isdisjoint(set(adj[k])):
								p2.add(k)
								if k in nodes:
									nodes.remove(k)
							else:
								return False
				else:
					return False
		return True,p1,p2

nodes = ['c1','c2','c3','c4','f1','f2','f3','f4']
edges = [('c1','f2',1),('c1','f1',1),
         ('c2','f2',1),('c2','f4',1),
         ('c3','f4',1),
         ('c4','f4',1)]

bipartiteGraph = Graph(nodes,edges)

candidates = ['c1','c2','c3','c4']
facilities = ['f1','f2','f3','f4']
adjDict = bipartiteGraph.adjdict

print(bipartiteGraph.isBipartite())

assigned = []

def matchCount(candidateList,facilityList,adjdict):
    if not candidateList or not facilityList:
        return 0
    else:
        cursor = candidateList[0]
        if len(adjdict[cursor]) == 0:
            return matchCount(candidateList.remove(cursor),facilities,adjdict)
        else:
            aux = [0]
            missed = 0
            for _ in adjdict[cursor]:
                if _[0] in facilityList:
                    aux.append(1+matchCount(candidateList[1:],facilityList[1:],adjdict))
                else:
                    missed += 1
                if(missed == len(adjdict[cursor])):
                    aux.append(matchCount(candidateList[1:],facilityList,adjdict))

            return max(aux)


print(matchCount(candidates,facilities,adjDict))