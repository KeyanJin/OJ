#include <iostream>
int main()
{
    int n = 0,m = 0;
    std::cin >> n >> m;
    int arr[n][m];
    for(int i = 0;i != n;i++)
    {
        for(int j = 0;j != m;j++)
        {
            int value;
            std::cin >> value;
            arr[i][j] = value;
        }
    }
    for(int i = 0;i != m;i++)
    {
        for(int j = n - 1;j >= 0;j--)
        {   if(j == 0)
            {
                std::cout << arr[j][i];
            }
            else {
                std::cout << arr[j][i] << " ";
            }
        }
        std::cout << std::endl;
    }
}