#include <cstddef>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
struct Rule
{
    std::string from;
    std::string to;
};

int bfs(const std::string start, const std::string target, const std::vector<Rule> rules)
{
    // string: 当前的字符串 int:当前步数
    std::queue<std::pair<std::string, int>> que;
    que.push({start, 0});
    std::unordered_set<std::string> vis;
    vis.insert(start);
    while (!que.empty())
    {
        std::string cur = que.front().first;
        int steps = que.front().second;
        que.pop();

        if (cur == target)
        {
            return steps;
        }

        for (const Rule rule : rules)
        {
            size_t pos = 0;
            while ((pos = cur.find(rule.from, pos)) != std::string::npos)
            {
                std::string next = cur.substr(0, pos) + rule.to + cur.substr(pos + rule.from.length());
                if (vis.find(next) == vis.end())
                {
                    vis.insert(next);
                    que.push({next, steps + 1});
                }
                pos += rule.from.length();
            }
        }
    }
    return -1;
}
int main()
{
    std::string str1, str2;
    std::cin >> str1 >> str2;
    std::string from, to;
    std::vector<Rule> rules;
    while (std::cin >> from >> to)
    {
        Rule r = {from, to};
        rules.push_back(r);
    }
    int ans = bfs(str1, str2, rules);
    if (ans <= 10 || ans != -1)
    {
        std::cout << ans << std::endl;
    }
    else
    {
        std::cout << "NO ANSWER!"<< std::endl;
    }
    return 0;
}