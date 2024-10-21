#include <cstddef>
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> nums;
    int n;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
        for(int i = 0;i != nums.size() - 1;i++)
        {
            if(nums.at(i) == temp)
            {
                nums.pop_back();
            }
        }
         
    }
    for(auto i : nums)
    {
        if(i != nums.at(nums.size() - 1))
        {
            std::cout << i << " ";
        }
        else
        {
            std::cout << i;
        }        
    }
    return 0;
}