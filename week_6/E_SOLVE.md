这个问题可以通过图的遍历来解决，利用广度优先搜索（BFS）来找到Bessie能在最短时间内到达的安全位置。由于这个问题的主要挑战在于模拟在指定时间内被陨石摧毁的网格，因此需要逐步判断哪些点是安全的。

### 问题的关键点：
1. **陨石摧毁的区域：** 陨石会摧毁它击中的位置和相邻的四个点，形成一个“摧毁区域”。陨石会在指定的时间 `Ti` 摧毁这些点，任何点的摧毁时间就是它的 `Ti`。
2. **Bessie的移动：** Bessie从 `(0, 0)` 出发，能在每秒内沿着x轴或y轴的方向移动。
3. **安全位置：** Bessie要避开所有在她移动过程中被陨石摧毁的点。

### 思路：
1. **初始化：** 使用一个二维数组 `destroyed` 来记录每个点被摧毁的时间。
2. **模拟陨石的摧毁过程：** 将所有陨石的摧毁信息存入 `destroyed` 数组，记录每个点的摧毁时间。
3. **BFS搜索：** 使用BFS来从 `(0, 0)` 开始搜索到一个安全点。Bessie只能在她到达的时间之前通过一个未被摧毁的点。
4. **边界条件：** 如果某个点被摧毁，Bessie不能通过该点；如果Bessie找到了安全的点，那么返回她到达该点的最短时间；如果没有找到安全的点，返回 `-1`。

### 解决步骤：
1. 将所有陨石的摧毁信息更新到一个二维数组中。
2. 使用广度优先搜索（BFS）从 `(0, 0)` 开始，按时间顺序探索每个点，检查是否能到达一个安全的位置。

### C++代码实现：

```cpp
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
        auto [x, y] = q.front();
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
```

### 代码说明：
1. **输入处理：**
   - 首先输入陨石的数量 `M`，然后对于每个陨石，记录它的 `(Xi, Yi)` 坐标和摧毁时间 `Ti`。
   - 使用 `destroyed` 数组存储每个点的摧毁时间，初始化为 `INF`（表示未摧毁），然后根据陨石的信息更新这些摧毁时间。
   
2. **BFS搜索：**
   - 使用一个队列来模拟Bessie的移动，从 `(0, 0)` 出发。
   - 使用一个 `time` 数组记录到达每个点的最短时间，初始值为 `INF`。
   - 通过BFS遍历所有相邻的点，如果当前点是未摧毁的且可以通过，更新该点的时间并将其加入队列。

3. **计算结果：**
   - 在遍历完所有点后，检查最短的时间是否有解，即找到一个可以到达且未被摧毁的点，返回最短时间。如果没有找到，返回 `-1`。

### 时间复杂度：
- **空间复杂度：** O(N^2)，因为我们存储了 `destroyed` 和 `time` 数组，每个数组的大小为 `N * N`，其中 `N` 是 305（即 300+1）。
- **时间复杂度：** O(M + N^2)，其中 `M` 是陨石的数量，每个陨石最多影响一个点的摧毁时间。BFS 遍历的复杂度是 O(N^2)，因为最多可能遍历所有的点。

### 结论：
这个解决方案利用BFS搜索算法在满足时间复杂度要求的情况下有效地解决了问题，能够处理最多50,000个陨石的情况。