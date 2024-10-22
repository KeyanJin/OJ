#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char * reverse(const char * str)
{
    char * temp_s = (char *)malloc(sizeof(char) * ((strlen(str)) + 1));
    for(int i = strlen(str) - 1;i >= 0;i--)
    {
        temp_s[strlen(str) - i - 1] = str[i];
    }
    return temp_s;
}
int main(void)
{
    char  str[100];
    scanf("%s",str);
    char * str2 = reverse(str);
    int a = strcmp(str, str2);
    if(a == 0)
    {
        printf("yes");
    }else {
        printf("no");
    }
    free(str2);
    return 0;
}