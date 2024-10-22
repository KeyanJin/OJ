#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
int main()
{
    int N;
    std::cin >> N;
    std::vector<int> nums(N);
    for(int i = 0;i != N;i++)
    {
        int n;
        std::cin >> n;
        nums.push_back(n);
    }
    for(int i = 0;i != nums.size();i++)
    {
        for(int j = 0;j < nums.size() - i - 1;j++)
        {
            if(nums.at(j) > nums.at(j + 1))
            {
                auto temp = nums.at(j);
                nums.at(j) = nums.at(j + 1);
                nums.at(j + 1) = temp;
            }
        }
    }
    auto itr = nums.begin();
    while (itr != nums.end() - 1) {
        if(*itr == *(itr + 1))
        {
            
        }
    }
    for(auto i : nums)
    {
        std::cout << i << " ";
    }
    return 0;
}