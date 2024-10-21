#include <stdio.h>
#include <string.h>
void func1(char * str)
{
    char * temp = str;
    while(*temp)
    {
        *temp += 3;
        if(*temp > 'z')
        {
            *temp -= 26;
        }
        temp++;
    }
}
void func2(char * str)
{
    int start = 0;
    int end = strlen(str) - 1;
    while(start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}
void func3(char * str)
{
    while(*str)
    {
        if(*str >= 65 && *str <=90)
        {
            *str += 32;
        }else
        {
            *str -= 32;
        }
        str++;
    }
}
int main(void)
{
    char str[51];
    scanf("%s",str);
    func1(str);
    func2(str);
    func3(str);
    char * temp = str;
    while(*temp)
    {
        printf("%c",*temp);
        temp++;
    }
    return 0;
}