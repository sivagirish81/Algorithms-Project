#include<stdio.h>
#include<stdlib.h>

/*
	We have n units of a resource to be allocated to r projects. n and r are
	integers and resource allocation is in integer units only. If j, 0<=j<=n, units of
	the resource are allocated to project i, then the resulting net profit is P (i,j).
	Design an algorithm to allocate the resource to the r projects so as to
	maximize the total net profit. Analyze its time complexity.
*/

/*
	Input:Adjacency matrix representing the profit gained by providing j resorces to i'th project.
	Output:The number of resources to be allocated to each project inorder to get maximum profit.
	Providing extra Resources to a project will result in a no extra profit.(optional)
*/
int res[100][100];
int count=0;
void Profitter(int **JR,int row,int col);
/*
// The vector v stores current subset. 
void getAllPossibilities(int arr[], int n, int v[], int sum) 
{ 
    // If remaining sum is 0, then print all 
    // elements of current subset. 
	printf("I'm Here\n");
	int l=sizeof(v)/sizeof(v[0]);
	int s=l+1;
	printf("s=%d\n",s);
	int v1[s];
    if (sum == 0) { 
        for (int x=0;x<n;x++) 
		{
			if (x<l)
			{
				res[count][x]=v[x];
				printf("%d ",v[x]);
			}
			else
				res[count][x]=0;
				
		}
		return;
	}
	if (n==0)
	{
		return;
	}
	for (int i=0;i<s-1;i++)
	{
		v1[i]=v[i];
	}
	getAllPossibilities(arr, n - 1, v, sum);//Without including last element
	v1[s]=arr[n-1];
	printf("v1[0]=%d ",v1[0]);
	getAllPossibilities(arr, n - 1, v1, sum - arr[n - 1]);
}
  
// Wrapper over printAllSubsetsRec() 
void getPossibilities(int arr[], int n, int sum) 
{ 
    int* v=(int*)malloc(n*sizeof(int));
    getAllPossibilities(arr, n, v, sum); 
} 
*/
void Profitter(int **JR,int row,int col)
{
	while (
}

int get_next_permutation(int *permutation, int n) {
	int i;
	int j;
	int k;
	int temp_int;
	int swaps;

	//find i
	for(i = n-2; i >= 0; i--) {
		if(permutation[i] < permutation[i+1]) {
			break;
		}
	}
	if(i == -1) {
		return 0;
	}

	for(j = i+1; j < n; j++) {
		if(permutation[j] < permutation[i]) {
			break;
		}
	}
	j--;

	temp_int = permutation[i];
	permutation[i] = permutation[j];
	permutation[j] = temp_int;

	//printf("DEBUG*i=%d,j=%d*", i, j); print_permutation(permutation, n);
	swaps = (n-1-i)/2;	
	for(k = 0; k < swaps; k++) {
		temp_int = permutation[i+1+k];
		permutation[i+1+k] = permutation[n-1-k];
		permutation[n-1-k] = temp_int;
	}
	return 1;
}

int main()
{
	int **JR={{100,150,175,175,175},{120,135,140,147,147},{80,105,105,105,105}};
	//Job Resource Array
	//Row Wise:Project No.
	//Column Wise:No. Of Resources
	//Value:Profit gained by allocating column no. of resources to row'th project
	//Profitter(JR,3,5);
	int arr[5]={0,1,2,3,4};
	for (int i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	}
	/*
	getPossibilities(arr,5,5);
	for (int i=0;i<count;i++)
	{
		for (int j=0;j<5;j++)
		{
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}*/
	genPermutations(
	
}

	