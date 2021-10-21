intArray = [1,2,5,8,7,9,4,6,3,4,8]

def isSum(n,arr):
    for k in arr:
        if n-k in arr:
            return True

def anotherTry(n,arr):
    arr2 = [n-k for k in arr]
    

print(isSum(13,intArray))