#include <iostream>
#include <vector>
#include <string>

int main()
{
    int n;
    double all,part;
    std::cin >> n;
    std::cin >> all >> part;
    double percentage = part / all;
    std::vector<std::string> effection;
    for(int i = 0;i != n - 1;i++)
    {
        double new_all,new_part;
        std::cin >> new_all >> new_part;
        double new_percentage = new_part / new_all;
        double f = new_percentage - percentage;
        if(f > 0.05)
        {
            effection.push_back("better");
        }else if(f < -0.05)
        {
            effection.push_back("worse");
        }
        else 
        {
            effection.push_back("same");
        }
    }
    for(auto i : effection)
    {
        std::cout << i << std::endl;
    }

    return 0;
}