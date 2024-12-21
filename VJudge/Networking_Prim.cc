#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

int main() {
    int P, R;
    
    while (cin >> P >> R, P != 0) {
        vector<vector<int>> adj(P + 1, vector<int>(P + 1, INT_MAX)); // 初始化图
        vector<Edge> edges;
        
        // 读入所有的边
        for (int i = 0; i < R; ++i) {
            int u, v, weight;
            cin >> u >> v >> weight;
            adj[u][v] = min(adj[u][v], weight); // 同一对点之间可能有多个路线，选择最短的
            adj[v][u] = min(adj[v][u], weight);
        }
        
        // Prim算法实现最小生成树
        vector<bool> inMST(P + 1, false); // 标记点是否在最小生成树中
        vector<int> minWeight(P + 1, INT_MAX); // 存储从树中到每个点的最小边的权重
        minWeight[1] = 0; // 从点1开始
        int totalWeight = 0;
        
        for (int i = 1; i <= P; ++i) {
            // 选择当前未在树中的点，且minWeight最小的点
            int u = -1;
            for (int j = 1; j <= P; ++j) {
                if (!inMST[j] && (u == -1 || minWeight[j] < minWeight[u])) {
                    u = j;
                }
            }
            
            // 添加这个点到MST中
            inMST[u] = true;
            totalWeight += minWeight[u];
            
            // 更新minWeight
            for (int v = 1; v <= P; ++v) {
                if (!inMST[v] && adj[u][v] != INT_MAX && adj[u][v] < minWeight[v]) {
                    minWeight[v] = adj[u][v];
                }
            }
        }
        
        // 输出最小生成树的总权重
        cout << totalWeight << endl;
        
        // 处理多个数据集之间的空行
        if (cin.peek() != EOF) {
            cout << endl;
        }
    }
    
    return 0;
}
