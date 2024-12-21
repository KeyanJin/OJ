#include <iostream>
int ans = 0;
int k, M;
struct item
{
    int count;
    int loves[100];
    bool vis[100];
};
item arr[6];
void func(int love, int k_)
{
    if (love > M)
    {
        ans++;
        return;
    }
    if (k_ == k)
    {
        return;
    }
    for(int i = k_;i < arr[k_].count;i++)
    {
        for(int j = 0;)
    }
}

int main()
{
    std::cin >> k >> M;
    for (int i = 0; i < k; i++)
    {
    }
    return 0;
}