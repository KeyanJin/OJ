#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> nums;
    for(int i = 0;i != N;i++)
    {
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
    }
    std::sort(nums.begin(),nums.end());
    for(auto i : nums)
    {
        std::cout << i << " ";
    }
    return 0;
}