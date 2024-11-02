#include <iostream>
#include <string>
#include <sstream>
#include <vector>
void to_lower(std::string &str)
{
    for(auto &i : str)
    {
        if(i <= 'Z' && i >= 'A')
        {
            i += 32;
        }
    }
}
int main()
{
    std::string word;
    std::cin >> word;
    to_lower(word);
    std::cin.ignore();
    std::string sentence;
    std::getline(std::cin,sentence);
    std::istringstream record(sentence);
    std::string temp;
    int count = 0;
    int index = -1;
    std::vector<std::string > strs;
    while(record >> temp)
    {
        to_lower(temp);
        strs.push_back(temp);
    }
    for(auto i : strs)
    {
        if(word == i)
        {
            count++;
        }
    }
    for(int i = 0;i != strs.size();i++)
    {
        if(strs[i] == word)
        {
            index = i;
            break;
        }
    }
    if(index != -1)
    {
        std::cout << count << " " << index;
    }
    else
    {
        std::cout << index;
    }
    return 0;
}