#include <stdio.h>
const char  str[] = "0123456789ABCDEF";
void func(int x,int m,char * str2,int index)
{
    if(x == 0)
    {
        str2[index] = '0';
        str2[index + 1] = '\0';
        return;
    }
    int a = x / m;
    int b = x % m;
    func(a,m,str2,index);
    str2[index] = str[b];
    index++;

}
int main(void)
{
    char str2[100];
    int x,m;
    scanf("%d %d",&x,&m);
    func(x, m, str2, 0);
    printf("%s",str2);

}