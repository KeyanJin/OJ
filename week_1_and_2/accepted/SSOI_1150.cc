#include <iostream>
#include <vector>
int main()
{
    int n;
    std::cin >> n;
    for(int i = 2;i != n + 1;i++)
    {
        std::vector<int> nums;
        int sum = 0;
        for(int j = 1;j * j <= i;j++)
        {
            if(i % j == 0)
            {
                int k = i / j;
                if(j != k && k != i)
                {
                    nums.push_back(j);
                    nums.push_back(k);
                }
                else 
                {
                    nums.push_back(j);
                }
            }
        }
        for(auto i : nums)
        {
            sum += i;
        }
        if(sum == i)
        {
            std::cout << i << std::endl;
        }
    }
}