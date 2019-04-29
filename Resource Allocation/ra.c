#include <stdio.h>

void generate(int n_balls, int n_boxes, int count, int combs[][n_boxes])
{
    if(n_boxes<=0) return;
    else if (n_boxes==1) {
        combs[count][0] = n_balls;
        count+=1;
    }
    else
    {
        for(int b = 0; b<=n_balls; ++b)
        {
            combs[count][n_boxes-1] = b;
            generate(n_balls-b,n_boxes-1,count,combs);
        }
    }
    
    
}

int fact(int n)
{
    if(n==1) return 1;
    else
    {
        return n*fact(n-1);
    }
    
}



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

    int z = fact(n-1+r)/(fact(r)*fact(n-1));

    int combs[z][r];

    generate(n-1,r,count,combs);

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

    int sum=0;
    for(int i=0; i<r; ++i)
    {
        printf("%d ",combs[res][i]);
        sum+=combs[res][i];
    }
    printf("\n");

    printf("Total profit:%d\n",sum);

    //print res's combination
    //print total profit




}