#include <iostream>
int n,k;
int ans = 0;
void dfs(int pos,int sum,int flag)
{
    if(pos >= k)
    {
        if(sum == n)
        {
            ans++;
        }
        return;
    }
    for(int i = flag;i <= n - sum;i++)
    {
        dfs(pos + 1, sum + i, i);
    }
}

int main()
{
    std::cin >> n >> k;
    dfs(0,0,1);
    std::cout << ans;
    return 0;
}