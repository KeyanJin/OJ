// H - 吃奶酪
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
int n;
bool eaten[16];
double x_arr[16];
double y_arr[16];
double ans;
double min_ = 1e5 + 1;

void dfs(double length, int count, double x, double y)
{
    if (count == n)
    {
        min_ = std::min(min_, length);
        ans = min_;
        return;
    }
    else
    {
        for (int i = 0; i != n; i++)
        {
            if (eaten[i] == false)
            {
                eaten[i] = true;
                dfs(length + sqrt(pow(x_arr[i] - x, 2) + pow(y_arr[i] - y, 2)), count + 1, x_arr[i], y_arr[i]);
                eaten[i] = false;
            }
        }
    }
}
int main()
{
    std::cin >> n;
    for (int i = 0; i != n; i++)
    {
       std::cin >> x_arr[i];
       std::cin >> y_arr[i];
    }
    memset(eaten, false, sizeof(eaten));
    dfs(0.0, 0, 0, 0);
    printf("%.2lf",ans);
    return 0;
}
