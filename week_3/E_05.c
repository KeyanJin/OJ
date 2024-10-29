#include <stdio.h>
#define FALSE 0
#define TRUE 1
#include <math.h>
int is_prime(int val)
{
    if(val == 1)
    {
        return FALSE;
    }
    if(val == 2 || val == 3)
    {
        return TRUE;
    }else if(val % 2 == 0 || val % 3 == 0)
    {
        return FALSE;
    }
    else
    {
        for(int i = 5;i * i <= val;i++)
        {
            if(val % i == 0)
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}
int is_paraline(int val)
{   
    int digits = 1;
    int result = 0;
    int temp = val;
    while(temp / 10 != 0)
    {
        digits++;
        temp /= 10;
    }
    int new_temp = val;
    while(new_temp / 10 != 0)
    {
        result += new_temp % 10 * pow(10,digits - 1);
        digits--;
        new_temp /= 10;
    }
    if(result == val)
    {
        return TRUE;
    }else
    {
        return FALSE;
    }
}
int main(void)
{
    // int a,b;
    // scanf("%d %d",&a,&b);
    // for(int i = a;i <= b;i++)
    // {
    //     if(is_paraline(i) && is_prime(i))
    //     {
    //         printf("%d\n",i);
    //     }
    // }
    // return 0;        
    int val = 102;
    int digits = 1;
    int result = 0;
    int temp = val;
    while(temp / 10 != 0)
    {
        digits++;
        temp /= 10;
    }
    int new_temp = val;
    while(new_temp / 10 != 0)
    {
        result += new_temp % 10 * pow(10,digits - 1);
        digits--;
        new_temp /= 10;
    }
    printf("%d",result);
}
  