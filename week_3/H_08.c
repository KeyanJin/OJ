#include <stdio.h>
int main(void)
{
    int n; // 杨辉三角的行数
    scanf("%d",&n);
    int arr[n][n];
    for(int i = 0;i < n;i++)
    {
        arr[i][i] = 1;
        arr[i][0] = 1;
    }
    for(int i = 2;i < n;i++)
    {
        for(int j = 1;j < i;j++)
        {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j <= i;j++)
        {
            if(arr[i][j] != 0)
            {
                printf("%d ",arr[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
