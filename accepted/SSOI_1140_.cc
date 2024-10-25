#include <iostream>
#include <string>
bool match(std::string m_str,std::string s_str)
{
    int i = 0;
    int j = 0;
    while(i < m_str.size() && j < s_str.size())
    {
        if(m_str.at(i) == s_str.at(j))
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == s_str.size())
    {
        return true;
    }
    else {
        return false;
    }
}
int main()
{
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;
    if(match(str1, str2))
    {
        std::cout << str2 << " is substring of " << str1;
    }else if(match(str2, str1))
    {
        std::cout << str1 << " is substring of " << str2;
    }else 
   {
        std::cout << "No substring";    
    }
    return 0;
}