#include <iostream>
#include <string>
int main()
{
    int k;
    std::string str;
    std::cin >> k >> str;
    int diff = 0;
    int flag = 0;
    for(int i = 0;i != k - 1;i++)
    {
        std::string temp;
        std::cin >> temp;
        diff = (temp[0] - str[0] + 26) % 26;
        for(int j = 1;j != str.size();j++)
        {
            if(((temp[j] - str[j] + 26) % 26) != diff)
            {
                flag++;
                std::cout << i + 1 << " ";
                break;
            }
        }
    }
    if(flag == 0)
    {
        std::cout << "true";
    }
    return 0;
}