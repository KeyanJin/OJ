#include <iostream>
#include <vector>
int main()
{
    int n;
    std::vector<int> nums;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
    }
    int min = nums.at(0);
    int max = nums.at(0);
    for(auto i : nums)
    {
        if(i > max)
        {
            max = i;
        }
        if(i < min)
        {
            min = i;
        }
    }
    int diff = max - min;
    std::cout << diff;
    return 0;
}