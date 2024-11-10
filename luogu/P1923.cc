#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    int n,k;
    std::cin >> n >> k;
    std::vector<int> nums;
    for(int i = 0;i != n;i++)
    {
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
    }
    std::sort(nums.begin(),nums.end());
    std::cout << nums[k];
    return 0;
}