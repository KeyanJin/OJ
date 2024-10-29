#include <iostream>
#include <vector>

int main()
{
    int num;
    int count = 0;
    std::cin >> num;
    std::vector<int> status;
    if(num % 3 == 0)
    {
        status.push_back(3);
    }
    if(num % 5 == 0)
    {
        status.push_back(5);
    }
    if(num % 7 == 0)
    {
        status.push_back(7);
    }
    count = status.size();
    if(count >= 2)
    {
        for(auto i = status.begin();i != status.end();i++)
        {
            if(i == status.end() - 1)
            {
                std::cout << *i;
            }
            else
            {
                std::cout << *i << " ";
            }
        }
    }else if(count == 1)
    {
        std::cout << status.at(0);
    }else if(count == 0)
    {
        std::cout << 'n';
    }
    return 0;
}