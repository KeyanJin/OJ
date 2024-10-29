#include <stdio.h>
#include <math.h>

int main(void)
{
    double x1,y1,x2,y2;
    scanf("%lf %lf",&x1,&y1);
    scanf("%lf %lf",&x2,&y2);
    if(fabs(x1) <= 10000 && fabs(x2) <= 10000 && fabs(y1) <= 10000 && fabs(y2) <= 10000)
    {
        double model = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
        printf("%.3f",model);
    }
    return 0;
}