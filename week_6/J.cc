// J - 单词接龙
#include <algorithm>
#include <iostream>
#include <string>
const int N = 512;
int n;
std::string s[N];
int arr[N][N];
int ans;
int used[N];

void init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 1; k < std::min(s[i].size(), s[j].size()); k++)
            {
                if (s[i].substr(s[i].size() - k) == s[j].substr(0, k))
                {
                    arr[i][j] = k;
                    // 此处应该break，只取最小重叠长度
                    break;
                }
            }
        }
    }
}

void dfs(std::string str, int cur)
{
    ans = std::max(ans, (int)str.size());
    for (int i = 0; i != n; i++)
    {
        if (used[i] < 2 && arr[cur][i] != 0)
        {
            used[i]++;
            dfs(str + s[i].substr(arr[cur][i]), i);
            used[i]--;
        }
    }
}
int main()
{
    std::cin >> n;
    for (int i = 0; i != n; i++)
    {
        std::cin >> s[i];
    }
    init();
    char ch;
    std::cin >> ch;
    for (int i = 0; i != n; i++)
    {
        if (ch == s[i][0])
        {
            used[i]++;
            dfs(s[i], i); // 次数参数应该是i
            // used[i]++; 在这里++无法正确执行
        }
    }
    std::cout << ans;
    return 0;
}