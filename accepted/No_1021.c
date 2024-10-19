#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num;
    scanf("%d",&num);
    if(num >= 0 && num <= 127)
    {
        printf("%c",num);
    }
    return 0;
}
