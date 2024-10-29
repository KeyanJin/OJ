#include <cmath>
#include <iostream>
#include <vector>
int main()
{
    int n;
    int result;
    std::cin >> n;
    std::vector<int> digits;
    int temp = abs(n);
    while(temp / 10 != 0)
    {
        int digit = temp % 10;
        if(true)
        {
            digits.push_back(digit);
        }
        temp /= 10;
    }
    digits.push_back(temp);
    if(n < 0)
    {
        std::cout << "-";
        for(int i = 0;i != digits.size();i++)
        {
            if(digits.at(0) == 0 && i == 0)
            {
                continue;
            }
            else
            {
                std::cout << digits.at(i);
            }
        }
    }
    else if(n > 0)
    {
        for(int i = 0;i != digits.size();i++)
        {
            if(digits.at(0) == 0 && i == 0)
            {
                continue;
            }
            else
            {
                std::cout << digits.at(i);
            }
        }
    }
    {
        std::cout << 0;
    }
    return 0;
}