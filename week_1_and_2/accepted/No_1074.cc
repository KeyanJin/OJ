#include <iostream>

int main()
{
    int rest = 0;
    int deposit = 0;
    bool is_defective = false;
    int de_month = 0;
    for(int i = 0;i != 12;i++)
    {
        rest += 300;
        int budget;
        std::cin >> budget;
        if(budget > rest)
        {
            is_defective = true;
            de_month = i + 1;
        }else if((rest - budget) / 100 > 0)
        {
            int k = (rest - budget) / 100;
            deposit += k * 100;
            rest = rest - k * 100 - budget;
        }
        else 
        {
            rest = rest - budget;
        }
    }
    if(is_defective)
    {
        std::cout << -de_month;
        return 0;
    }
    else
    {
        deposit *= 1.2;
        rest += deposit;
        std::cout << rest;
        return 0;
    }
}