#include <stdio.h>

int main(void)
{
    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    int bad_apples = y / x + 1;
    int perfect_apple = n - bad_apples;
    printf("%d",perfect_apple);
    return 0;
}