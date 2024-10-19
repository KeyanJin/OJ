#include <stdio.h>

int main(void)
{
    double FDegree;
    scanf("%lf",&FDegree);
    double CDegree = 5 * (FDegree - 32) / 9;
    printf("%0.5f",CDegree);
    return 0;
}