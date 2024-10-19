#include <iostream>


int main()
{
    int max = -1,n;
    std::cin >> n;
    for (int i = 0,temp = -1;i != n;i++)
    {
        std::cin >> temp;
        if(temp > max)
        {
            max = temp;
        }
    }
    std::cout << max;



    return 0;
}