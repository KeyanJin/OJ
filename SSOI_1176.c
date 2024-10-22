#include <stdio.h>
typedef struct Student
{
    int ID;
    double score;
}student;

int main(void)
{
    int n,k;
    scanf("%d %d",&n,&k);
    student s;
    for(int i = 0;i != n;i++)
    {
        int id;
        double score;
        scanf("%d %lf",&id,&score);
        if(i == k)
        {
            s.ID = id;
            s.score = score;
        }
    }
    printf("%d %g",s.ID,s.score);
    return 0;
}