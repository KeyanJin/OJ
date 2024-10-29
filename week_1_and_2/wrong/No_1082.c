#include <stdio.h>
#include <math.h>


int main(void)
{
    int a,b,n;
    scanf("%d %d %d",&a,&b,&n);
    double x = (double)a / b;
    int y = x * pow(10, n);
    int z = y % 10;
    printf("%d",z);
    return 0;

}