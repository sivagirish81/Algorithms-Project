# Python program to print all subsets with given sum 
  
# The vector v stores current subset.
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
    
def getAllSubsetsRec(arr, n, v, sum,res) :  
    if (sum == 0) : 
        #print(v)
        res.append(v)
        return 
    if (n == 0): 
        return 
    getAllSubsetsRec(arr, n - 1, v, sum,res) 
    v1 = [] + v 
    v1.append(arr[n - 1]) 
    getAllSubsetsRec(arr, n - 1, v1, sum - arr[n - 1],res) 
  
 
def getAllSubsets(arr, n, sum,res): 
    v = [] 
    getAllSubsetsRec(arr, n, v, sum,res) 

def getMaxProfit(JR,res,m,n):
    x=getPossibilities(res,m,n)
    #print(x)
    maximum=0
    maxpath=[]
    print("Possible Ways of allocating Resources are:")
    k=0
    a=[]
    for i in x:
        tot=0
        a=[]
        for j in range(m):
            tot+=JR[j][i[j]]
            a.append(JR[j][i[j]])
            #print(JR[j][i[j]],end="")
            print(i[j],end="")
            print("->",end="")
        print("=",tot)
        print()
        if (tot>maximum):
            maxpath=[]
            maximum=tot
            maxpath=i
    return maxpath

#Main Function    
JR=[[100,150,175,175,175,175],[120,135,140,147,147,147],[80,105,105,105,105,105]]
arr = [0,1,2,3,4,5]
m=len(JR)
#print(len(JR))
n=len(JR[0])
#sum = 5
sum=5
res=[]
n = len(arr) 
getAllSubsets(arr, n, sum,res)
#print(res)
result=getMaxProfit(JR,res,m,n)
#print(result)
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

