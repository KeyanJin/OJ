#include <iostream>
#include <vector>

int main()
{
    int n;
    std::vector<int> nums;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }
    int count = 0;
    for(auto i : nums)
    {
        int one = i % 10;
        int ten = i / 10 % 10;
        int han = i / 100 % 10;
        int tho = i / 1000;
        int result = one - tho - han - ten;
        if(result > 0)
        {
            count++;
        }
    }
    std::cout << count;
    return 0;
}