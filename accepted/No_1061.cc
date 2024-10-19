#include <stdio.h>
#include <iostream>
#include <vector>

int main()
{
    int n;
    int sum = 0;
    std::vector<int> nums;
    std::cin >> n;
    for(int i = 0;i < n;i++)
    {
        int temp = 0;
        std::cin >> temp;
        nums.push_back(temp);
    }
    for(auto i : nums)
    {
        sum += i;
    }
    double average = (double)sum / n;
    printf("%d %.5f",sum,average);
    return 0;
}