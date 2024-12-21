#include <stdio.h>

int prime(int n);
void solve(int n, int m);

int a[22], b[21], n, k, t = 0;

int main()
{
    int i;
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    solve(n, k);
    printf("%d", t);
}

void solve(int n, int m) // 从n里面选m个数字
{
    int i, sum;
    if (m == 0)
    {
        sum = 0;
        for (i = 0; i < k; i++)
            sum += b[i];
        if (prime(sum))
            t++;
        return;
    }
    for (i = n; i >= m; i--)
    {
        b[m - 1] = a[i];
        solve(i - 1, m - 1);
    }
}

int prime(int n)
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
