#include <stdio.h>

int main(void)
{
    int meter;
    scanf("%d",&meter);
    double secondsOfBike = meter / 3.0;
    double secondsOfWalk = meter / 1.2;
    secondsOfBike += 50;
    if(secondsOfBike < secondsOfWalk)
    {
        printf("Bike");
    }else if(secondsOfBike > secondsOfWalk)
    {
        printf("Walk");
    }
    else
    {
        printf("All");
    }
    return 0;
}