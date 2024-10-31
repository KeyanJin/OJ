#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n][n];
    int left = 0,right = n - 1;
    int top = 0;
    int bottom = n - 1;
    for(int value = 1;value <= n * n;value++)
    {
        for(int i = left;i <= right ;i++)
        {
            arr[top][i] = value;
            value++;
        }
        top++;
        for(int j = top;j <= bottom;j++)
        {
            arr[j][left] = value;
            value++;
        }
        right--;
        for(int k = right;k >= left;k++)
        {
            arr[bottom][k] = value;
            value++;
        }
        bottom--;
        for(int l = bottom;l >= top;l--)
        {
            arr[left][l] = value;
        }
        left++;
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            printf("%3d",arr[i][j]);
        }
    }
    return 0;
}