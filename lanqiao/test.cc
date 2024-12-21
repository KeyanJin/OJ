#include <algorithm>
#include <iostream>
int get_max(int n)
{
    int ans = 1;
    int tmp = n;
    while(tmp / 10 != 0)
    {
        int dec = tmp % 10;
        ans = std::max(dec,ans);
        tmp /= 10;
    }
    return ans;
}
int main()
{
    int a = 91;
    int ans = get_max(a);
    std::cout << ans;
    return 0;
}