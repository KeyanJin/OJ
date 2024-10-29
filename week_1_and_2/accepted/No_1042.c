#include <stdio.h>

int main(void)
{
    char ch;
    scanf("%c",&ch);
    int temp = ch;
    if(temp % 2 == 0)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
    return 0;
}