#include <algorithm>
#include <iostream>
#include <vector>


// 并查集数据结构
struct UnionFind
{
    std::vector<int> parent, rank;
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

// 边结构
struct Edge
{
    int u, v, weight;
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

int main()
{
    int P, R;
    while (std::cin >> P)
    {
        if(P == 0)
        {
            break;
        }
        std::cin >> R;
        std::vector<Edge> edges;
        for (int i = 0; i < R; i++)
        {
            int u, v, w;
            std::cin >> u >> v >> w;
            edges.push_back({u - 1, v - 1, w}); // 将节点编号从 1 到 P 转换为 0 到 P-1
        }

        // 按权重排序
        std::sort(edges.begin(), edges.end());

        // Kruskal 算法
        UnionFind uf(P);
        int total_length = 0;
        for (std::vector<Edge>::iterator i = edges.begin();i != edges.end();i++)
        {
            if (!uf.same(i->u, i->v))
            {
                uf.unite(i->u, i->v);
                total_length += i->weight;
            }
        }

        std::cout << total_length << std::endl;
    }
    return 0;
}