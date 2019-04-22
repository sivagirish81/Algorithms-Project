#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main()
{
    int n;

    while(1)
    {
        printf("Enter number of pairs of BW\n");
        scanf("%d",&n);     //number of BW pairs

        if(n<3) //arranging for n=1,2 can be done in trivial method in n moves
        {
            printf("Please enter a number greater than or equal to three\n");   
        }
        else
        {
            break;
        }
    }
        

    char * input = (char*)malloc((2*n+3)*sizeof(char)); //the algorithm is such that it requires 2 spaces before the string.
    input[2*n+2] = '\0';                                //setting the null character
    int str_length = 2*n+2;
    input[0] = '_';
    input[1] = '_';

    for(int i=2; i<str_length; i+=2)        
    {
        input[i]='B';
        input[i+1] = 'W';
    }

    printf("Before arranging:\n");
    printf("%s\n",input);

    arrange(input,n);

    printf("After arranging:\n");
    printf("%s\n",input);

}