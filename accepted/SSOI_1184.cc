#include <iostream>
#include <set>

#include <vector>
int main()
{
    int N;
    std::cin >> N;
    std::vector<int> nums;
    for(int i = 0;i != N;i++)
    {
        int n;
        std::cin >> n;
        nums.push_back(n);
    }
    for(int i = 0;i != nums.size() - 1;i++)
    {
        for(int j = 0;j < nums.size() - i - 1;j++)
        {
            if(nums.at(j) > nums.at(j + 1))
            {
                std::swap(nums.at(j),nums.at(j + 1));
            }
        }
    }
    std::set<int> new_nums(nums.begin(),nums.end());
    std::cout << new_nums.size() << std::endl;
    for(auto i : new_nums)
    {
        std::cout << i << " ";
    }
    return 0;
}