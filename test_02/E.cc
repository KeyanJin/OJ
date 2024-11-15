#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::vector<long long> nums;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        long long an;
        std::cin >> an;
        nums.push_back(an);
    }
    int count = 0;
    for(auto i = nums.begin();i != nums.end();i++)
    {
        count++;
        int index = count;
        for(auto j = i + 1;j <= nums.end();j++)
        {
            index++;
            if(j == nums.end())
            {
                std::cout << 0 << " ";
                break;
            }
            if(*j > *i)
            {
                std::cout << index << " ";
                break;
            }
        }
    }
    return 0;
}