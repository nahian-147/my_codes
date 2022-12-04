def isArmsotrong(p):
    k = str(p)

    sum = 0

    for _ in k:
        sum += int(_)**3
    
    if sum == p :
        return True
    else:
        return False

print(isArmsotrong(153))