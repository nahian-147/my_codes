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

nodes = ['a','b','c','d']
edges = [('a','b',1),('a','d',2),('b','c',1),('c','d',2)]
g = Graph(nodes,edges)
g.add_node('e')
g.add_node('f')
g.add_edge('d','e',3)
g.add_edge('e','d',1)
g.add_edge('c','f',1)
print(g.isBipartite())
