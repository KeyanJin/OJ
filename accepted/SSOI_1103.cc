#include <iostream>
#include <vector>
int main()
{
    std::vector<int> apples;
    for(int i = 0;i != 10;i++)
    {
        int apple;
        std::cin >> apple;
        apples.push_back(apple);
    }
    int height;
    int count = 0;
    std::cin >> height;
    for(auto i : apples)
    {
        if(height + 30 >= i)
        {
            count++;
        }
    }
    std::cout << count;
    return 0;
}