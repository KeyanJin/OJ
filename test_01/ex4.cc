#include <iostream>
#include <string>
#include <vector>
void reverse(std::string & str)
{
    int start = 0;
    int end = str.size() - 1;
    while(start < end)
    {
        char temp = str.at(start);
        str.at(start) = str.at(end);
        str.at(end) = temp;
        start++;
        end--;
    }
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<int > nums;
    for(int i = 0;i != n;i++)
    {
        int count = 0;
        int a1,a2;
        std::cin >> a1 >> a2;
        for(int i = a1;i <= a2;i++)
        {
            std::string str = std::to_string(i);
            std::string str2 = str;
            reverse(str);
            if(str.compare(str2) == 0)
            {
                count++;
            }
        }
        nums.push_back(count);
    }
    for(auto i : nums)
    {
        std::cout << i << std::endl;
    }
    return 0;
}