#include <iostream>
#include <string>
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
    std::string str;
    std::cin >> str;
    reverse(str);
    std::cout << str;
    return 0;
}