#include <stdio.h>
int main()
{
    int x,n;
    scanf("%d %d",&x,&n);
    int flag = 0;
    int swim = 0;
    while(flag != n)
    {
        if(x % 7 == 6 || x % 7 == 0)
        {
            flag++;
            x++;
            continue;
        }
        else
        {
            swim += 250;
            x++;
            flag++;
        }
    }
    printf("%d",swim);
    return 0;
}