#include <iostream>

int main()
{
    int m,n,sum = 0;
    std::cin >> m;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        int taken_pills;
        std::cin >> taken_pills;
        sum += taken_pills;
        if(sum > m)
        {
            std::cout << n - i;
            break;
        }
    }
    if(sum <= m)
    {
        std::cout << 0;
    }
    return 0;
}