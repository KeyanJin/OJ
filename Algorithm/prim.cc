#include <iostream>
#include <algorithm>

const int INF = 1e5;
const int N = 5008;
int mp[N][N];
int n, m;
bool vis[N];
int dist[N]; // 节点到集合的最小距离
int prim(int pos)
{
    dist[pos] = 0; // 初始化 把初始的一个点到集合的距离改为0
    int res = 0;   // 返回值
    for (int i = 1; i <= n; i++)
    {
        int t = -1; // 找集合外距离集合距离最小的点
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (t == -1 || dist[t] > dist[j]))
            {
                // 如果j这个节点不在集合里 并且t是初始值或者dist[t]不是最小值的时候更新t值
                t = j;
            }
        }
        if (dist[t] == INF)
        { // 如果找到的t距离集合的距离是INF表示t无法到达集合
            return INF;
        }
        res += dist[t];
        vis[t] = true;
        for (int j = 1; j <= n; j++)
        { // 通过新加入的t来更新其他所有节点距离集合的距离
            dist[j] = std::min(dist[j], mp[t][j]);
        }
    }
    return res;
}
int main()
{
    std::cin >> n >> m;
    memset(dist, 0x3f, sizeof dist); // 初始化
    memset(mp, 0x3f, sizeof mp);
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        mp[a][b] = std::min(mp[a][b], c); // 输入边
        mp[b][a] = std::min(mp[b][a], c);
    }
    int t = prim(1);
    if (t == INF)
    {
        std::cout << "orz" << '\n';
    }
    else
    {
        std::cout << t << '\n';
    }
    return 0;
}