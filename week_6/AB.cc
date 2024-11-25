
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

bool ans = false;
std::vector<std::string> words;
bool arr[512][512];
bool used[512];
void init()
{
    for (int i = 0; i != words.size(); i++)
    {
        for (int j = 0; j != words.size(); j++)
        {
            if (words[i][words[i].size() - 1] == words[j][0])
            {
                arr[i][j] = true;
            }
        }
    }
}
void dfs(std::string str, int cur)
{
    if (str[str.size() - 1] == 'm')
    {
        std::cout << "Yes.";
        ans = true;
        return;
    }
    else
    {
        for (int i = 0; i != words.size(); i++)
        {
            if (arr[cur][i] == true && used[i] == false)
            {
                used[i] = true;
                dfs(words[i], i);
                used[i] = false;
            }
        }
    }
}
int main()
{
    memset(arr, false, sizeof(arr));
    memset(used, false, sizeof(used));
    init();
    for (;;)
    {
        std::string str;
        std::cin >> str;
        if (str == "0")
        {
            break;
        }
        words.push_back(str);
    }
    for (int i = 0; i != words.size() && ans == false; i++)
    {
        if (words[i][0] == 'b')
        {
            used[i] = true;
            dfs(words[i], i);
            if(ans == true)
            {
                break;
            }
            used[i] = false;
        }
    }
}