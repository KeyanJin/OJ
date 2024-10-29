#include <stdio.h>
void print_time(int time)
{
    int hour = time / 60;
    int minute = time % 60;
    int a = 7 - hour;
    if(a < 0)
    {
        a = a + 24;
    }
    printf("%02d:%02d",a,60 - minute);
}
int main()
{
    int s,v;
    scanf("%d %d",&s,&v);
    int time = 0;
    if(s % v == 0)
    {
        time = s / v + 10;
    }
    else
    {
        time = s / v + 10 + 1;
    }
    print_time(time);
    return 0;
}