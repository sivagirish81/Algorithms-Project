#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Function Declarations*/
long int partition(long int arr[], long int low, long int high);
void quickSort(long int arr[],long int low,long int high);
void QuickSortF(long int *arr,long int low,long int high);
long int partitionF(long int *arr,long int l,long int h);
void swap(long int *arr,long int x,long int y);
long int partitionL(long int arr[], long int low, long int high);
long int partition_r(long int arr[], long int low, long int high);
void quickSortL(long int arr[], long int low, long int high);
long int partitionH(long int arr[], long int low, long int high);
long int partitionerH(long int arr[], long int low, long int high);
void quickSortH(long int arr[], long int low, long int high);
void Writer(long int arr[],long int n,double time);

/*Time ELapsed Function*/
double time_elapsed(struct timespec *start, struct timespec *end)
{
	double t;
	t=(end->tv_sec - start->tv_sec);
	t+=(end->tv_nsec - start->tv_nsec)*0.000000001;
	return t;
}

/*Method 1
+Quick Sort with selecting Last element a pivot
*/
long int partition(long int arr[], long int low, long int high) 
{ 
    long int pivot = arr[high]; 
    long int i =low-1;
  
    for (long int j=low; j<=high-1;j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++; 
            swap(arr,i,j); 
        } 
    } 
    swap(arr,i + 1,high); 
    return (i + 1); 
} 
 
void quickSort(long int arr[],long int low,long int high) 
{ 
    if (low<high) 
    { 
        long int s=partition(arr,low,high); 
        quickSort(arr,low,s-1); 
        quickSort(arr,s+1,high); 
    } 
} 

/*Method 3
+Lomuto Method of Partitioning
*/
long int partitionL(long int arr[], long int low, long int high) 
{ 
    long int pivot = arr[high]; 
    long int i = (low - 1);
    for (long int j = low; j <= high - 1; j++) 
	{ 
        if (arr[j] <= pivot) { 
  
            i++; 
            swap(arr,i,j); 
        } 
    } 
    swap(arr,i + 1,high); 
    return (i + 1); 
} 

long int partition_r(long int arr[], long int low, long int high) 
{ 

    //srand(time(NULL)); 
    long int random = low + rand() % (high - low); 
    swap(arr,random,high); 
    return partitionL(arr, low, high); 
} 

void quickSortL(long int arr[], long int low, long int high) 
{ 
    if (low < high) 
	{ 

        long int s = partition_r(arr, low, high); 
        quickSortL(arr, low, s - 1); 
        quickSortL(arr, s + 1, high); 
    } 
}  

/*Method 4
+Hoare Method of Parttioning
*/

long int partitionH(long int arr[],long int low,long int high) 
{ 
    long int pivot = arr[low]; 
    long int i = low - 1;
	long int j = high + 1; 
	//long int count=(low+high)*(low+high);
	//long int t=0;
    while (1) 
	{ 
        do { 
            i++; 
        } while (arr[i] < pivot); 
        do { 
            j--; 
        } while (arr[j] > pivot);  
        if (i >= j) 
            return j; 
  
        swap(arr,i,j); 
		
    } 
} 
   
long int partitionerH(long int arr[],long int low,long int high) 
{ 
    //srand(time(NULL)); 
    long int random = low + rand() % (high - low);  
    swap(arr,random,low); 
    return partitionH(arr, low, high); 
} 
  
void quickSortH(long int arr[], long int low, long int high) 
{ 
    if (low < high) { 
        long int pi = partitionerH(arr, low, high); 
        quickSortH(arr, low, pi); 
        quickSortH(arr, pi + 1, high); 
    } 
} 

void Writer(long int arr[],long int size,double time)
{
	printf("Enter the file name");
	char outnum[1000];
	scanf("%[^\n]%*c", outnum);
	FILE* nfp=fopen(outnum,"w");
	char* str=(char*)malloc(100*sizeof(char*));
	for (int i=0;i<size;i++)
	{
		sprintf(str,"%d",arr[i]);
		fputs(str,nfp);
		fputs("\n",nfp);
	}
	sprintf(str,"%f",time);
	fputs(str,nfp);
	fclose(nfp);
	return;
	
}

int main()
{
	struct timespec start,end;
	printf("Enter Full Path to input File:\n");
	char path[1000];
	scanf("%[^\n]%*c", path);
	printf("%s \n",path);
	FILE* fp;
	fp=fopen(path,"r");
	long int size;
	fscanf(fp,"%d",&size);
	printf("%li\n",size);
	long int temp[size];
	long int h=0;
	char *ch=(char*)malloc(sizeof(char*));
	long int arr[size];
	while((ch = fscanf(fp,"%d",&arr[h])) != EOF && h<size )
       {
		   h+=1;
       }
	   for (long int i=0;i<size;i++)
	   {
		   temp[i]=arr[i];
	   }
	
    /*Last Element Pivot*/
	clock_t t;
	t = clock();
	quickSort(arr,0,size-1);
	t = clock() - t; 
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	Writer(arr,size,time_taken);
	for (long int i=0;i<size;i++)
	   {
		   arr[i]=temp[i];
	   }
	/*Lomuto Partition*/
	t = clock();
	quickSortL(arr,0,size-1);
	t = clock() - t; 
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	/*
	for (int i=0;i<size;i++)
	   {
		   printf("%d ",arr[i]);
	   }
	   printf("fdbjbgjba");*/
	Writer(arr,size,time_taken);
	/*Hoare Partition*/
	   for (long int i=0;i<size;i++)
	   {
		   arr[i]=temp[i];
	   }
	t = clock();
	quickSortH(arr,0,size-1);
	/*
	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%QuickSortH%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	   for (int i=0;i<size;i++)
	   {
		   printf("%d\n ",arr[i]);
	   }
	   printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");*/
	t = clock() - t; 
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	Writer(arr,size,time_taken);
	
}

	
	
	
	
	
	