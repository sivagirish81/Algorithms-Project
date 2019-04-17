#include<stdio.h>
#include<stdlib.h>
#define B 66
#define W 77	
int main()
{
	int n;
	printf("Enter Number of counters:");
	scanf("%d",&n);
	int *A=(int*)malloc(sizeof(int*));
	int W=(int)W;
	int B=(int)B;
	for (int i=0;i<n;i++)
	{
		if (A[i]%2==0)
		{
			A[i]=W;
		}
		else
		{
			A[i]=B;
		}
	}
	int *B=(int*)malloc(sizeof(int*));
	B=Align_Counter(A);
	Display(A);
	Display(B);
}

void Align_Counter(int *A)
{
	int len=sizeof(A)/sizeof(A[0]);
	for (int i=n;i<len;i++)
	{
		