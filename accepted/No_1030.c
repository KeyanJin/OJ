#include <stdio.h>
#include <math.h>
#define PI 3.14

int main(void)
{
    double redius;
    scanf("%lf",&redius);
    if(redius > 0 && redius <= 100)
    {
        double volume = PI * pow(redius,3.0) * 4 / 3;
        printf("%.2f",volume);
    }


    return 0;
}