#include <iostream>
#include <vector>
int main()
{
    int m;
    int n;
    std::vector<int> pills_taken;
    std::cin >> m;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        int temp;
        std::cin >> temp;
        pills_taken.push_back(temp);
    }
    int pills = m;
    int not_taken = 0;
    for(int i = 0;i != n;i++)
    {
        if(pills_taken.at(i) <= not_taken)
        {
            not_taken -= pills_taken.at(i);
        }
        else
        {
            not_taken++;
        }
    }
    std::cout << not_taken;
    return 0;
}