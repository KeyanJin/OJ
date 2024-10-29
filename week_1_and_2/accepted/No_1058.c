#include <stdio.h>
#include <math.h>

int main(void)
{

    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a != 0)
    {
        double delta = b * b - 4 * a * c;
        if(delta == 0)
        {
            double x = -b / (2 * a);
            printf("x1=x2=%.5f",x);
        }else if(delta > 0)
        {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            printf("x1=%.5f;x2=%.5f",x2,x1);
        }
        else
        {
            printf("No answer!");
        }
    }
    return 0;
}