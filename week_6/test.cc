#include <iostream>
#include <string>
#include <vector>

bool dfs(const std::vector<std::string> &words, bool arr[512][512], bool used[512], std::string current, int curIndex)
{
    if (current.back() == 'm')
    {
        return true;
    }
    for (int i = 0; i < words.size(); ++i)
    {
        if (arr[curIndex][i] && !used[i])
        {
            used[i] = true;
            if (dfs(words, arr, used, words[i], i))
            {
                return true;
            }
            used[i] = false;
        }
    }
    return false;
}

int main()
{
    std::vector<std::string> words;
    bool arr[512][512] = {false};
    bool used[512] = {false};

    std::string str;
    while (true)
    {
        std::cin >> str;
        if (str == "0")
        {
            break;
        }
        words.push_back(str);
    }

    int wordCount = words.size();
    for (int i = 0; i < wordCount; ++i)
    {
        for (int j = 0; j < wordCount; ++j)
        {
            if (words[i].back() == words[j].front())
            {
                arr[i][j] = true;
            }
        }
    }

    for (int i = 0; i < wordCount; ++i)
    {
        if (words[i].front() == 'b')
        {
            std::fill(used, used + 512, false);
            used[i] = true;
            if (dfs(words, arr, used, words[i], i))
            {
                std::cout << "Yes." << std::endl;
                return 0;
            }
        }
    }
    std::cout << "No." << std::endl;
    return 0;
}