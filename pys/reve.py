def mxwght(paths):
    mx = 0
    p = ''
    for path in paths:
        sm = 0
        for node in path.split():
            sm += int(node)
        if sm > mx:
            mx = sm
            p = path
    return mx,p

class Tree:
    def __init__(self):
        self.left = None
        self.right = None
        self.val = None
    def paths(self,root):
        if root is None:
            return []
        if (root.left == None and root.right == None):
            return [str(root.val)]
        
        return [str(root.val) + ' ' + l for l in self.paths(root.right) + self.paths(root.left)]

root = Tree()
root.val = 10
root.left = Tree()
root.left.val = 20
root.right = Tree()
root.right.val = 15
root.left.left = Tree()
root.left.left.val = 30
root.right.right = Tree()
root.right.right.val = 30
root.right.left = Tree()
root.right.left.val = 10


p = root.paths(root)

print(mxwght(p)[1])
