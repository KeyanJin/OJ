#include <stdio.h>
int main(void)
{
    int a,b;
    scanf("%d %d",&a,&b);
    int mod = a % 7;
    for(int i = 1;i != b;i++)
    {
        mod = (mod * 3) % 7;
    }
    switch (mod) 
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