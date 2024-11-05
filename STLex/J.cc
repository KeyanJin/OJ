#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    int n,j;
    std::vector<int> nums;
    std::cin >> n >> j;
    for(int i = 0;i != n;i++)
    {
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
    }
    std::sort(nums.begin(),nums.end());
    std::cout << nums.at(j);
    return 0;
}