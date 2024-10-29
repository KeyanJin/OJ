#include <stdio.h>

int main(void)
{
    int x,a,y,b;
    scanf("%d %d %d %d",&x,&a,&y,&b);
    double increasing = (x * a - b * y) / (a - b);
    printf("%.2f",increasing);
    return 0;
}
