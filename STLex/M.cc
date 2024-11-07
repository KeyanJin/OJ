#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector<std::string> strs;
    int n;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        std::string temp;
        std::cin >> temp;
        strs.push_back(temp);
    }
    std::sort(strs.begin(),strs.end(),[](std::string &str1,std::string &str2)->bool
    {
        return (str1 + str2 > str2 + str1);
    });
    for(auto i : strs)
    {
        std::cout << i;
    }
    return 0;
}
