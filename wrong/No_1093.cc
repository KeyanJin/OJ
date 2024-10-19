#include <cmath>
#include <cstdio>
#include <stdio.h>
float func(float x,int n)
{
    float result = 0;
    for(int i = 0;i <= n;i++)
    {
        result += pow(x,i);
    }
    return result;
}
int main()
{
    float x;
    int n;
    scanf("%f %d",&x,&n);
    printf("%.2f",func(x,n));
    return 0;
}