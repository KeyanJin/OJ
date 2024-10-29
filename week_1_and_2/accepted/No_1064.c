#include <stdio.h>


int main()
{
    int n,gold_count = 0,silver_count = 0,bronze_count = 0;
    scanf("%d",&n);
    
    for(int i = 0;i < n;i++)
    {
        int gold = 0;
        int silver = 0;
        int bronze = 0;
        scanf("%d %d %d",&gold,&silver,&bronze);
        gold_count += gold;
        silver_count += silver;
        bronze_count += bronze;
    }
    int sum = gold_count + silver_count + bronze_count;
    printf("%d %d %d %d",gold_count,silver_count,bronze_count,sum);

    return 0;
}