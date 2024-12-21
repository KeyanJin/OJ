#include <stdio.h>
#include <stdlib.h>

int func(int n)
{
    if(n == 0)
    {
        return 0;
    }
    char binary[33];
    binary[32] = '\0';

    int index = 31;
    while(n > 0)
    {
        binary[index--] = (n % 2) ? '1' : '0';
        n = n / 2;
        
    }
}