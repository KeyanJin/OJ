#include <iostream>
#include <string>
void right_shift(std::string &str)
{
    for(auto &i : str)
    {
        i += 3;
        if((i > 'z' && i <= 'z' + 3) || i > 'Z' && i <= 'Z' + 3)
        {
            i -= 26;
        }
    }
}
void reverse(std::string &str)
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
void lowAndUp(std::string &str)
{
    for(auto &i : str)
    {
        if(i <= 'z' && i >= 'a')
        {
            i -= 32;
        }
        else
        {
            i += 32;
        }
    }
}
int main()
{
    std::string str;
    std::cin >> str;
    right_shift(str);
    reverse(str);
    lowAndUp(str);
    std::cout << str;
    return 0;
}