#include <iostream>
int main()
{
    int n,m;
    std::cin >> n;
    int arr[n][n];
    for(int i = 0;i != n;i++)
    {
        for(int j = 0;i != n;j++)
        {
            int temp;
            std::cin >> temp;
            arr[i][j] = temp;
        }
    }
    std::cin >> m;
    return 0;
}