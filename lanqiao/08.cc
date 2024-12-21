
#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;
    std::string a = "LANQIAO";
    int count = 0;
    for(auto i = str.begin();i != str.end();)
    {
        if(count == 6)
        {
            break;
        }
        size_t pos = str.find(a[count]);
        if(pos != std::string::npos)
        {
            str = str.substr(pos);
            count++;
        }
        else
        {
            break;
        }
    }
    if(count == 6)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
    return 0;
}