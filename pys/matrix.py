import numpy as np
import os
import time

class Matrix:
    row = 0
    column = 0
    m = np.array([[]],dtype='f8')
    def __init__(self,lst):
        self.row = len(lst)
        self.column = len(lst[0])
        self.m = np.array([[0.0 for k in range(self.column)] for i in range(self.row)], dtype='f8')
        for i in range(self.row):
            for j in range(len(lst[i])):
                self.m[i][j] = lst[i][j]
    
    def getMatrix(self):
        return self.m
    
    def __mul__(self,matrix):
        if not self.column == matrix.row:
            return False
        else:
            result = Matrix([[0.0 for k in range(matrix.column)] for i in range(self.row)])
            for i in range(self.row):
                for j in range(matrix.column):
                    result.m[i][j] = 0.0
                    for k in range(self.column):
                        result.m[i][j] += self.m[i][k]*matrix.m[k][j]
            return result

    def __rmul__(self,n):
        result = Matrix([[0.0 for k in range(self.column)] for i in range(self.row)])
        for i in range(self.row):
            for j in range(self.column):
                result.m[i][j] = n*self.m[i][j]
        return result


    def __add__(self,matrix):
        if not (self.row,self.column) == (matrix.row,matrix.column):
            return False
        else:
            result = Matrix([[0.0 for k in range(self.column)] for i in range(self.row)])
            for i in range(self.row):
                for j in range(self.column):
                    result.m[i][j] = self.m[i][j] + matrix.m[i][j]
            return result

    def __sub__(self,matrix):
        if not (self.row,self.column) == (matrix.row,matrix.column):
            return False
        else:
            result = Matrix([[0.0 for k in range(self.column)] for i in range(self.row)])
            for i in range(self.row):
                for j in range(self.column):
                    result.m[i][j] = self.m[i][j] - matrix.m[i][j]
            return result

    def tr(self):
        t = self.column
        self.column = self.row
        self.row = t
        result = Matrix([[0.0 for k in range(self.row)] for i in range(self.column)])
        for i in range(self.row):
            for j in range(self.column):
                result.m[j][i] = self.m[i][j]
        return result

    def __str__(self):
        s = '\n'
        for k in range(self.row):
            for l in range(self.column):
                s += ' {0:>10}'.format(round(self.m[k][l],4))
            s += '\n'
        return s

    def augment(self,matrix):
        if not self.row == matrix.row:
            return False
        else:
            result = Matrix([[0.0 for k in range(self.column + matrix.column)] for i in range(self.column)])
            for i in range(self.row):
                for j in range(self.column):
                    result.m[i][j] = self.m[i][j]
            for i in range(matrix.row):
                for j in range(matrix.column):
                    result.m[i][self.column+j] = matrix.m[i][j]
            result.column = self.column + matrix.column
            result.row = self.row
            return result

    def rref(self):
        result = Matrix([[0.0 for k in range(self.column)] for i in range(self.column)])
        result = self
        for k in range(result.row):
            if not result.m[k][k] == 0 :
                result.m[k] = result.m[k]/result.m[k][k]
            for _ in range(result.row):
                if not _ == k:
                    result.m[_] -= result.m[_][k]*result.m[k]
        return result


class I(Matrix):
    row = 0
    column = 0
    m = np.array([[]])
    def __init__(self,n):
        self.row = n
        self.column = n
        self.m = np.zeros((self.row,self.column))
        for k in range(n):
            self.m[k][k] = 1

class Vector(Matrix):
    row = 1
    column = 0
    m = np.array([[]])
    def __init__(self,lst):
        self.row = 1
        self.column = n
        self.m = np.zeros((self.row,self.column))
        for k in range(len(n)):
            self.m[1][k] = lst[k]
    

#M = Matrix(3,5)
#M.m = np.array([[1,3,5,5,0],[0,3,3,5,0],[1,3,1,5,0]])
#v = Matrix(5,1)
#v.m = np.array([[1],[2],[3],[4],[5]])
#R = v*v.transpose()

def makeG(n):
    for k in range(n):
        os.system('cls')
        G = Matrix(15,15)
        v = Matrix(15,1)
        v.m = np.floor(5*np.random.rand(15,1))
        G = G + v*v.transpose()
        print(G)
        time.sleep(2)


#M = Matrix(3,3)
#M.m = np.random.rand(3,3)
v = Matrix([[2],[1-5],[1]])
#v.m = np.random.rand(3,1)
#b = M*v
#b = b + v

#makeG(5)

i5 = I(5)

B_list = [[1,-2,1],[3,0,1],[2,7,5]]
B = Matrix(B_list)
P = (B.augment(I(3)))
print(P)
print(P.rref())
