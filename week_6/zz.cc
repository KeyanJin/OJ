#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 305;  // 网格大小，最多是300
const int INF = 1000000000;  // 无限大，用于初始化最短路径

// 方向数组：上下左右
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct Meteor {
    int x, y, t;
};

int destroyed[N][N];  // destroyed[x][y]记录点(x, y)被摧毁的时间，若没摧毁为INF

// 判断是否在有效范围内
bool inBounds(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    int M;
    cin >> M;
    
    // 初始化摧毁时间
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            destroyed[i][j] = INF;
        }
    }
    
    // 输入所有陨石信息
    vector<Meteor> meteors(M);
    for (int i = 0; i < M; i++) {
        cin >> meteors[i].x >> meteors[i].y >> meteors[i].t;
        // 记录陨石摧毁的点和周围的点
        for (int dxi = -1; dxi <= 1; dxi++) {
            for (int dyi = -1; dyi <= 1; dyi++) {
                if (abs(dxi) + abs(dyi) == 1) {  // 只摧毁相邻的4个点
                    int nx = meteors[i].x + dxi;
                    int ny = meteors[i].y + dyi;
                    if (inBounds(nx, ny)) {
                        destroyed[nx][ny] = min(destroyed[nx][ny], meteors[i].t);
                    }
                }
            }
        }
        destroyed[meteors[i].x][meteors[i].y] = min(destroyed[meteors[i].x][meteors[i].y], meteors[i].t);
    }
    
    // BFS从(0, 0)开始
    queue<pair<int, int>> q;  // (x, y)队列
    vector<vector<int>> time(N, vector<int>(N, INF));  // 记录从起点到各点的最短时间
    q.push({0, 0});
    time[0][0] = 0;
    
    while (!q.empty()) {
        auto x = q.front().first;
        auto y = q.front().second;
        q.pop();
        
        // 遍历上下左右四个方向
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            
            // 判断是否有效且未被摧毁
            if (inBounds(nx, ny) && time[nx][ny] == INF && time[x][y] + 1 < destroyed[nx][ny]) {
                time[nx][ny] = time[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    // 找到最小时间到达安全地点
    int result = INF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (time[i][j] < destroyed[i][j]) {
                result = min(result, time[i][j]);
            }
        }
    }
    
    if (result == INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}