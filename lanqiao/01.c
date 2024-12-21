#include <math.h>
#include <stdio.h>
int is_prime(int i)
{
    if(i == 1)
    {
        return 0;
    }
    if(i == 2 || i == 3)
    {
        return 1;
    }
    if(i % 2 == 0 || i % 3 == 0)
    {
        return 0;
    }
    for(int k = 5;i * k <= i;k++)
    {
        if(i % k == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int ans = 1;
    for(int i = sqrt(2024);i >= 2;i--)
    {
        if(is_prime(i) && 2024 % i == 0)
        {
            ans = i;
            break;
        }
    }
    printf("%d",ans);
    return 0;
}