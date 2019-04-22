from numpy import *

def Random_generator(size,fname):
    filename=fname+".txt"
    with open(filename,'w+') as Input:
        Input.write('{}\n'.format(str(size)))
        for i in range(size):
            x=random.randint(0,1000000)
            Input.write('{}\n'.format(str(x)))
        Input.close()

def Sorted_generator(size,fname):
    filename=fname+".txt"
    with open(filename,'a+') as Input:
        Input.write('{}\n'.format(str(size)))
        start=random.randint(0,10000)
        for i in range(size):
            x=random.randint(0,26)
            start+=x
            Input.write('{}\n'.format(str(start)))
        Input.close()

def RSorted_generator(size,fname):
    filename=fname+".txt"
    with open(filename,'a+') as Input:
        Input.write('{}\n'.format(str(size)))
        start=random.randint((size+10000),10000000)
        for i in range(size):
            x=random.randint(0,26)
            if (start-x>0):
                start-=x
            else:
                start-=0
            Input.write('{}\n'.format(str(start)))
        Input.close()

def Create_input(size,fname):
    filename=fname+".txt"
    with open(filename,'a+') as Input:
        Input.write('{}\n'.format(str(size)))
        for i in range(size):
            x=input("Enter the number:")
            Input.write('{}\n'.format(str(x)))
        Input.close()

fname=input("Enter name of input file:")
size=int(input("Enter size of input required:"));
print("Types Of input Available:")
print("1-Random")
print("2-Sorted in ascending Order")
print("3-sorted indescending order")
print("4-Create your own input");
i=int(input("Enter your choice:"))
if (i==1):
    Random_generator(size,fname)
elif (i==2):
    Sorted_generator(size,fname)
elif (i==3):
    RSorted_generator(size,fname)
elif (i==4):
    Create_input(size,fname)



