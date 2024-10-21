#include <stdio.h>
#include <string.h>

int main()
{
    char str[256];
    fgets(str,sizeof(str),stdin);
    int count = 0;
    for(int i = 0;i != strlen(str);i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            count++;
        }
    }
    printf("%d",count);
    
    return 0;
}