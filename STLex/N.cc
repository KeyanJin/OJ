#include <iostream>
#include <set>
int main()
{
    int n;
    std::cin >> n;
    std::string result = "";
    std::set<std::string> strs;
    for(int i = 0;i != n;i++)
    {
        std::string str;
        std::cin >> str;
        strs.insert(str);
    }
    for(auto i = strs.rbegin();i != strs.rend();i++)
    {
        result += *i;
    }
    std::cout << result;
    return 0;
}