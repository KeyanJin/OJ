#include <iostream>
#include <vector>
void func3(std::vector<int > &nums);
void func2(std::vector<int > &nums);

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int >> a;
    for(int i = 0;i != n;i++)
    {
        int m;
        std::cin >> m;
        std::vector<int > nums;
        for(int j = 1;j <= m;j++)
        {
            nums.push_back(j);
        }
        func2(nums);
        a.push_back(nums);
    }
    for(auto i : a)
    {
        for(auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
void func2(std::vector<int > &nums)
{
    if(nums.size() <= 3)
    {
        return;
    }
    else
    {
        for(auto i = nums.begin() + 2;i != nums.end();i += 2)
        {
            nums.erase(i);
        }
        func3(nums);
    }
}
void func3(std::vector<int > &nums)
{
    if(nums.size() <= 3)
    {
        return;
    }
    else
    {
        for(int i = 2;i < nums.size();i += 3)
        {
            nums.erase(nums.begin() + i);
        } 
        func2(nums);
    }
}