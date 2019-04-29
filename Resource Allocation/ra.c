#include <stdio.h>




int main()
{
    int r,n;
    scanf("%d",&r);
    scanf("%d",&n);

    int P[r][n];

    for(int i=0; i<r ; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            scanf("%d",&P[i][j]);
        }
    }   

    int a[r];

    for(int i=0; i<r; ++i) a[i] = 0;

    int count=0;

    //calculate value of C(n-1+r,r), say z

    int combs[z][r];

    generate(a,n-1,r,count,combs);

    int res = -1;

    int max = 0;

    for(int i=0; i<count; ++i)
    {
        int sum=0;
        for(int j=0; j<r; ++j)
        {
            sum+=P[j][combs[i][j]];
        }
        if(sum>max)
        {
            res = i;
            max = sum;
        }
    }

    //print res's combination
    //print total profit




}