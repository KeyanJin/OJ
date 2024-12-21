#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
int dx[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dy[] = {2, 2, -2, -2, 1, -1, 1, -1};
std::vector<int> ans;
struct pos
{
    int x;
    int y;
    int steps;
};

bool vis[10][10];
bool judge(int x,int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}
void bfs(int start_x,int start_y,int end_x,int end_y,std::queue<pos> que)
{
    pos p1 = {start_x,start_y,0};
    vis[start_x][start_y] = true;
    que.push(p1);
    while(!que.empty())
    {
        pos p2 = que.front();
        que.pop();
        if(p2.x == end_x && p2.y == end_y)
        {
            ans.push_back(p2.steps);
            return;
        }
        for(int i = 0;i != 8;i++)
        {
            int x_ = p2.x + dx[i];
            int y_ = p2.y + dy[i];
            if(judge(x_, y_) && vis[x_][y_] == false)
            {
                vis[x_][y_] = true;
                pos p3 = {x_,y_,p2.steps + 1};
                que.push(p3);
            }
        }
    }

}
int main()
{
    int n;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        std::queue<pos> que;
        memset(vis, false, sizeof vis);
        std::string str;
        std::cin >> str;
        int start_x = str[0] - 'a';
        int start_y = str[1] - '1';
        std::string str2;
        std::cin >> str2;
        int end_x = str2[0] - 'a';
        int end_y = str2[1] - '1';
        bfs(start_x,start_y,end_x,end_y,que);
    }
    for(auto i : ans)
    {
        std::cout << i << std::endl;
    }
    return 0;
}