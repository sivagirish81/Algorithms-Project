import copy

def enumerate(a,n_balls,n_boxes):
    if n_boxes<=0:
        return -1
    elif n_boxes==1:
        a[0]=n_balls
        combs.append(copy.deepcopy(a))
    else:
        for b in range(n_balls+1):
            a[n_boxes-1] = b
            enumerate(a,n_balls-b,n_boxes-1)
a=[0,0]
combs = []
enumerate(a,3,2)

res = -1

max = 0

P = [[0,1,2,100],[0,0,0,0]]



for i in range(len(combs)):
    sum = 0
    for j in range(len(combs[i])):
        sum+=P[j][combs[i][j]]
    #print(sum)
    if sum>max:
        res = i
        max = sum
     


print(combs[res])        
        