#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int one = n % 10;
    int ten = n / 10 % 10;
    int han = n / 100;
    printf("%d%d%d",one,ten,han);
    return 0;
}