#define PI 3.14159
#include <stdio.h>

int main(void)
{
    double redius,diameter,perimeter,area;
    scanf("%lf",&redius);
    if(redius > 0 && redius <= 10000)
    {
        diameter = redius * 2;
        perimeter = 2 * PI * redius;
        area = redius * redius * PI;
    }
    printf("%.4f %.4f %.4f",diameter,perimeter,area);
    return 0;
}