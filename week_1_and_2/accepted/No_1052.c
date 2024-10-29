#include <stdio.h>

int main(void)
{
    int weight;
    char isUrgency;
    int fee = 8;
    scanf("%d %c",&weight,&isUrgency);
    if(weight <= 1000)
    {
        fee = 8;
    }
    else
    {
        int over_part = weight - 1000;
        fee += (over_part / 500 + 1) * 4;
    }
    switch (isUrgency)
    {
    case 'y':
        fee += 5;
        break;
    case 'n':
        break;
    default:
        printf("Wrong status.");
        break;
    }
    printf("%d",fee);
    return 0;
}