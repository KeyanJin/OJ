#include <stdio.h>
int is_prime(int var)
{
    if(var == 1)
    {
        return 0;
    }
    else if(var == 2 || var == 3)
    {
        return 1;
    }
    else if(var % 2 == 0 || var % 3 == 0)
    {
        return 0;
    }
    else
    {
        for(int i = 5;i * i <= var;i++)
        {
            if(var % i == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
int is_paraline(int var)
{
    int temp = var;
    int result = 0;
    while(var != 0)
    {
        int digit = var % 10;
        result = result * 10 + digit;
        var /= 10;
    }
    if(result == temp)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    if(b > 100000000)
    {
        for(int i = a;i != 9999999;i++)
        {
            if(is_paraline(i) && is_prime(i))
            {
            printf("%d\n",i);
            }
        }
    }
    else
    {
        for(int i = a;i <= b;i++)
        {
            if(is_paraline(i) && is_prime(i))
            {
            printf("%d\n",i);
            }
        }
    }
}