
"""

We have n units of a resource to be allocated to r projects. n and r are
integers and resource allocation is in integer units only. If j, 0<=j<=n, units of
the resource are allocated to project i, then the resulting net profit is P (i,j).
Design an algorithm to allocate the resource to the r projects so as to
maximize the total net profit. Analyze its time complexity.

Input:Adjacency matrix representing the profit gained by providing j resorces to i'th project.
Output:The number of resources to be allocated to each project inorder to get maximum profit.
Providing extra Resources to a project will result in a no extra profit.(optional)

"""
def getMaxProfit( arr, JR,W, n): 
    dp = [0 for i in range(W + 1)] 
    ans = 0
    wt=
    for i in range(W + 1): 
        for j in range(n): 
            if (wt[j] <= i): 
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]) 
    return dp[W]

def getMaxProfitter(arr, JR,W, n):
    for 
def Remduplicates(d): 
    f=[]
    for i in d: 
        if i not in f: 
            f.append(i) 
    return f

# Python function to print permutations of a given list 
def permutation(permutations): 
    if len(permutations) == 0: 
        return []  
    if len(permutations) == 1: 
        return [permutations] 
    l = []  
    for i in range(len(permutations)): 
       m = permutations[i] 
       rempermutations = permutations[:i] + permutations[i+1:] 
       for p in permutation(rempermutations): 
           l.append([m] + p) 
    return l 

 

def getPossibilities(res,m,n):
    l=len(res)
    for i in res:
        for k in range(m):
            if (len(i)<(m)):
                i.append(0)
            else:
                break
            
    #print(res)
    p=[]
    for i in res:
        for k in permutation(i):
            p.append(k)
    return p
    

#Main Function    
#JR=[[100,150,175,175,175,175],[120,135,140,147,147,147],[80,105,105,105,105,105]]
path=input("Enter Input File Name:");
fpath="Input/"+path+".txt"
with open(fpath) as textFile:
    lines = [line.split() for line in textFile]

JR=[]
for line in lines:
    JR.append([int(l) for l in line])

print(JR)


#arr = [0,1,2,3,4,5]
m=len(JR)
print(m)
n=len(JR[0])
arr=[u for u in range(n) for u in range(n)]
print(arr)
#sum = 5
sum=n-1
res=[]
n = len(arr) 
getAllSubsets(arr, n, sum,res)
#print(res)
result=getMaxProfitter(JR,res,m,n)
print(result)
print("The Method of allocating resources which gives the maximum profit is ")
for i in result:
    print(i,end="")
    print("->",end="")
fin=0
#print(JR)
for j in range(m):
    fin+=JR[j][result[i]]
    i+=1
    #print(fin)
print(fin)

