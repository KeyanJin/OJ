#include <iostream>
#include <string>
void tolow(std::string &str)
{
    for(int i = 0;i != str.size();i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
}
void match(std::string str1,std::string str2)
{
    int j = 0;
    int i = 0;
    int count = 0;
    int index = 0;
    while(i < str1.size() && j < str2.size())
    {
        if(str1[i] == str2[j])
        {
            j++;
            i++;
        }
        else
        {
            i = 0;
            j = j - i + 1;
        }
        if(i == str1.size())
        {
            i = 0;
            count++;
            if(count == 1)
            {
                index = j - str1.size();
            }
        }
    }
    if(count == 0)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << count << " " << index;
    }
}
int main()
{
    std::string str1;
    std::string str2;
    std::getline(std::cin,str1);
    std::getline(std::cin,str2);
    tolow(str1);
    tolow(str2);
    match(str1, str2);
    return 0;
}