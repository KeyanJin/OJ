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
    int n, m;
    cin >> n >> m;
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
    if (cnt == n - 1)
    {
        cout << ans << '\n';
    }
    else
    {
        cout << "orz" << '\n';
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