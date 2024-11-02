#include <iostream>
#include <string>
int my_toupper(int c)
{
    if((c >= 'a') && (c <= 'z'))
    {
        return c + ('A' - 'a');
    }
    return c;
}
int main()
{
    std::string str;
    std::cin >> str;
    for(int i = 0;i != str.size();i++)
    {
        str[i] = my_toupper(str[i]);
    }
    std::cout << str;
    return 0;
}