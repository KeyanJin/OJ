
#include <algorithm>
#include <iostream>
#include <queue>
int ans = -1;

struct stp
{
    int value;
    int cost;
};
int get_max(int n)
{
    int ans_ = 1;
    int tmp = n;
    if(n < 10)
    {
        return n;
    }
    while(tmp / 10 != 0)
    {
        int dec = tmp % 10;
        ans_ = std::max(dec,ans_);
        tmp /= 10;
    }
    ans_ = std::max(ans_,tmp % 10);
    return ans_;
}
std::queue<stp> que;
void bfs()
{
    stp s1 = {1,0};
    que.push(s1);
    while(!que.empty())
    {
        stp s2 = que.front();
        que.pop();
        if(s2.value == 2024)
        {
            ans = s2.cost;
            return;
        }
        stp p3 = {s2.value + 1,s2.cost + 1};
        stp p4 = {s2.value + get_max(s2.value),s2.cost + 3};
        stp p5 = {s2.value * 2,s2.cost + 10};
        que.push(p3);
        que.push(p4);
        que.push(p5);
    }
}

int main()
{
    bfs();
    std::cout << ans;
    return 0;
}