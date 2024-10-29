#include <iostream>
int main()
{
    int n;
    std::cin >> n;
    int nums[n];
    int count = 0;
    for(int i = 0;i != n;i++)
    {
        int temp;
        std::cin >> temp;
        nums[i] = temp;
    }
    for(int i = 0;i != n - 1;i++)
    {
        for(int j = i + 1;j < n;j++)
        {
            if(nums[j] < nums[i])
            {
                count++;
            }
        }
    }
    std::cout << count;
    return 0;
}