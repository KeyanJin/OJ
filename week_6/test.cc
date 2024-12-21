#include <iostream>
const int SIZE = 30;
int ans = 0;
int n,k;
int a[SIZE],b[SIZE];
bool is_prime(int n)
{
    int i;
    for (i = 2; i < n; i++)
        if (n % i == 0)
            break;
    if (i == n || n == 2)
        return 1;
    else
        return 0;
}
void solve(int n,int m)
{
    
    if(m == 0)
    {
        int sum = 0;
        for(int i = 0;i < k;i++)
        {
            sum += b[i];
        }
        if(is_prime(sum))
        {
            ans++;
        }
        return;
    }
    for(int i = n;i >= m;i--)
    {
        b[m - 1] = a[i];
        solve(i - 1,m - 1);
    }
}
int main()
{
    std::cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> a[i];
    }
    solve(n,k);
    std::cout << ans;
    return 0;
}