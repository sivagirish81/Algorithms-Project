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


path=input("Enter Input File Name:");
fpath="Input/"+path+".txt"
with open(fpath) as textFile:
    lines = [line.split() for line in textFile]

P=[]
for line in lines:
    P.append([int(l) for l in line])
print(P)

#P = [[0,1,2,100],[0,0,0,0]]
r=len(P)
n=len(P[0])
a=[0 for i in range(r)]
combs = []
enumerate(a,n-1,r)

res = -1

max = 0

#P = [[0,1,2,100],[0,0,0,0]]



for i in range(len(combs)):
    sum = 0
    for j in range(len(combs[i])):
        sum+=P[j][combs[i][j]]
    #print(sum)
    if sum>max:
        res = i
        max = sum
     

k=0
print(combs[res])
for i in combs[res]:
    if (k<r):
        print("Allocate Project {} with {} resources.".format(str(k+1),str(i)))
        k+=1
su=0
k=0
for i in combs[res]:
    if (k<r):
        su+=P[k][i]
        k+=1
print("Total Profit gained:",su)
        
