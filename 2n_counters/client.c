#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);

    if(n<3)
    {
        printf("Please enter a number greater than or equal to three\n");
        exit(0);
    }

    char * input = (char*)malloc((2*n+3)*sizeof(char));
    input[2*n+2] = '\0';
    int str_length = 2*n+2;
    input[0] = '_';
    input[1] = '_';

    for(int i=2; i<str_length; i+=2)        //0 and 1 to be empty
    {
        input[i]='B';
        input[i+1] = 'W';
    }

    arrange(input,n);

    printf("After arranging:\n");
    printf("%s\n",input);

}