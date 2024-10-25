#include <iostream>
int main()
{
    int matrix[5][5];
    for(int i = 0;i != 5;i++)
    {
        for(int j = 0;j != 5;j++)
        {
            int value;
            std::cin >> value;
            matrix[i][j] = value;
        }
    }
    int n1,n2;
    std::cin >> n1 >> n2;
    int temp[5];
    for(int i = 0;i != 5;i++)
    {
        temp[i] = matrix[n1 - 1][i];
    }
    for(int i = 0;i != 5;i++)
    {
        matrix[n1 -1][i] = matrix[n2 - 1][i];
    }
    for(int i = 0;i != 5;i++)
    {
        matrix[n2 - 1][i] = temp[i];
    }
    for(int i = 0;i != 5l;i++)
    {
        for(int j = 0;j != 5;j++)
        {
            if(j != 5)
            {
                std::cout << matrix[i][j] << " ";
            }
            else
            {
                std::cout << matrix[i][j];
            }
        }
        std::cout << std::endl;
    }
}