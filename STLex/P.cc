#include <iostream>
#include <sstream>
#include <string>
#include <vector>
void to_lower(std::string &str)
{
    for(auto &i : str)
    {
        if(i >= 65 && i <= 90)
        {
            i += 32;
        }
    }
}
int main()
{
    std::vector<std::string> words;
    std::string word;
    std::cin >> word;
    to_lower(word);
    std::cin.ignore();
    std::string sentence;
    std::getline(std::cin,sentence);
    std::istringstream record(sentence);
    std::string temp;
    while(record >> temp)
    {
        words.push_back(temp);
    }
    int count = 0;
    for(auto &i : words)
    {
        to_lower(i);
        if(i == word)
        {
            count++;
        }
    }
    if(count != 0)
    {
        int index = sentence.find(word);
        std::cout << count << " " << index;
    }
    else
    {
        std::cout << -1;
    }
    return 0;
}