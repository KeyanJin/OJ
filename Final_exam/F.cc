// #include <algorithm>
// #include <cstring>
// #include <iostream>
// const int INF = 1e5;
// const int N = 100;
// int mp[N][N];
// bool vis[N];
// int dist[N];
// int n, m;
// int prim(int pos)
// {
//     dist[pos] = 0;
//     int res = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         int t = -1;
//         for (int j = 1; j <= n; j++)
//         {
//             if (vis[j] != true && (t == -1 || dist[t] > dist[j]))
//             {
//                 t = j;
//             }
//         }
//         if (dist[t] == INF)
//         {
//             return INF;
//         }
//         res += dist[t];
//         vis[t] = true;
//         for (int j = 1; j <= n; j++)
//         {
//             dist[j] = std::min(dist[j], mp[t][j]);
//         }
//     }
//     return res;
// }

// int main()
// {
//     double c;
//     int n, m;
//     std::cin >> c >> n >> m;
//     memset(dist, 0x3f, sizeof(dist));
//     memset(mp, 0x3f, sizeof(mp));
//     for (int i = 1; i <= n; i++)
//     {
//         int a, b, c;
//         std::cin >> a >> b >> c;
//         mp[a][b] = std::min(mp[a][b], c);
//         mp[b][a] = std::min(mp[b][a], c);
//     }
//     int ans = prim(1);
//     if(ans > c)
//     {
//         std::cout << "No" << std::endl;
//     }
//     else
//     {
//         std::cout << "Yes" << std::endl;
//     }
//     return 0;
// }
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 2e5 + 8;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, 1, 0, 0};
int fa[N];
struct Edge
{
    int u, v, w;
    bool operator<(const Edge &t) const
    {
        return w < t.w;
    }
} edge[N];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void solve()
{
    int n, m,c;
    cin >> c >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge, edge + m);
    int cnt = 0; // 边数
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    int ans = 0; // 边长

    for (int i = 0; i < m; i++)
    {
        int ta = edge[i].u, tb = edge[i].v;
        ta = find(ta), tb = find(tb);
        if (ta == tb)
            continue;
        else
        {
            cnt++;
            ans += edge[i].w;
            fa[ta] = tb; // 把这两个点合并
        }
    }
    if(ans > c)
    {
        std::cout << "No" << std::endl;
    }
    else
    {
        std::cout << "Yes" << std::endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T ;
    while (T--)
    {
        solve();
    }

    return 0;
}