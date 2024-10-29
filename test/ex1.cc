#include <iostream>
#include <string>
#include <vector>
int main()
{
    int n;
    std::cin >> n; 
    std::string str;
    std::cin >> str;
    std::string alph = "abcdefghijklmnopqrstuvwxyz";
    std::vector<int> diff;
    std::vector<int > a;
    for(auto i = str.begin();i != str.end() - 1;i++)
    {
        if(*(i + 1) < *i)
        {
            int temp = *i - *(i + 1);
            diff.push_back(temp);
        }
        else
        {
            int temp = *(i + 1) - *i;
            diff.push_back(temp);
        }
        
    }
    for(int code = 0;code != n - 1;code++)
    {
        std::vector<int> new_diff;
        std::string temp;
        std::cin >> temp;
        for(auto i = temp.begin();i != temp.end() - 1;i++)
        {
            if(*(i + 1) < *i)
        {
            int temp = *(i + 1) - *i + 26;
            new_diff.push_back(temp);
        }
            else
            {
                int temp = *(i + 1) - *i;
                new_diff.push_back(temp);
            }
        }
        for(int i = 0;i != diff.size();i++)
        {
            if(diff.at(i) != new_diff.at(i))
            {
                a.push_back(code + 1);
                break;
            }
        }

    }
    for(auto i : a)
    {
        std::cout << i << " ";
    }
    return 0;
}