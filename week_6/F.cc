// // F - 选数
// #include <iostream>
// #include <set>
// const int size = 20;
// int nums[size + 1];
// bool vis[size + 1];
// int n, k;

// std::set<int> primes;
// bool is_prime(int a)
// {
//     if (a == 1)
//     {
//         return false;
//     }
//     else if (a == 2 || a == 3)
//     {
//         return true;
//     }
//     else if (a % 2 == 0 || a % 3 == 0)
//     {
//         return false;
//     }
//     else
//     {
//         for (int i = 5; i * i <= a; i += 6)
//         {
//             if (a % i == 0 || a % (i + 2) == 0)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// }
// void dfs(int sum, int pos)
// {
//     if (pos == k + 1)
//     {
//         if (is_prime(sum))
//         {
//             primes.insert(sum);
//         }
//         return;
//     }
//     for (int i = 0; i != n; vis[i] = true, i++)
//     {
//         if (vis[i] == false)
//         {
//             vis[i] = true;
//             dfs(sum + nums[i], pos + 1);
//             vis[i] = false;
//         }
//     }
// }
// int main(void)
// {
//     std::cin >> n >> k;
//     for (int i = 0; i != n; i++)
//     {
//         std::cin >> nums[i];
//     }
//     dfs(0, 1);
//     std::cout << primes.size();
//     return 0;
// }
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