class Graph:
    neigbrhood = {}
    reverse_neighbourhood = {}

    def __init__(self,ngb):
        self.neigbrhood = ngb
        self.reverse()

    def add_node(self,node):
        self.neigbrhood[node] = []

    def add_edges(self,node1,node2):
        if node1 not in self.neigbrhood:
            self.neigbrhood[node1] = [node2]
        else:
            self.neigbrhood[node1].append([node2])

    def print_neighbourhood(self):
        print(self.neigbrhood)
    
    def print_reverse_neighbourhood(self):
        print(self.reverse_neighbourhood)
    
    def reverse(self):
        for ngbrs in self.neigbrhood:
            for node in self.neigbrhood[ngbrs]:
                if not node in self.reverse_neighbourhood:
                    self.reverse_neighbourhood[node] = [ngbrs]
                else:
                    self.reverse_neighbourhood[node].append(ngbrs)

    def shortest_path(self,source,destination):
        if source == destination:
            return source[1]
        else:
            return destination[1] + min([self.shortest_path(source,nghbr) for nghbr in self.reverse_neighbourhood[destination]])
            


n = {('s',1):[('a',1),('b',1),('c',1)],
     ('a',1):[('d',3),('e',1)],
     ('b',1):[('e',1)],
     ('c',1):[('f',2)],
     ('d',3):[('g',1)],
     ('e',1):[('h',1)],
     ('f',2):[('h',1)],
     ('g',1):[('z',3)],
     ('h',1):[('z',3)],
     ('z',3):[] }

graph = Graph(n)
print(graph.shortest_path(('s',1),('z',3)))