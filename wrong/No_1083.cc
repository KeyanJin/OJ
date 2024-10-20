#include <cmath>
#include <stdio.h>
int main(void)
{
    int a,b;
    scanf("%d %d",&a,&b);
    unsigned long long days = pow(a,b);
    unsigned long long day = days % 7;
    switch (day) 
    {
        case 0:
            printf("Sunday");
            break;
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
        default:
            break;
    }
    return 0;
}