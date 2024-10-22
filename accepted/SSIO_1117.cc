#include <iostream>
#include <vector>
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums;
    for(int i = 0;i != n;i++)
    {
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
    }
    for(int i = 0;i != n;i++)
    {
        for(int j = i + 1;j != n;j++)
        {
             if(nums[i] == nums[j])
            {
                nums[j] = -1;
            }
        }
    }
    for(auto i : nums)
    {
        if(i >= 1)
        {
            std::cout << i << " ";
        }
    }
    return 0;
}