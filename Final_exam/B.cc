#include <iostream>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    int N;
    std::cin >> N;
    int r1 = -1, r2 = -1;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        std::cin >> x >> y;
        int tmp1 = (x - x1) * (x - x1) + (y - y1) * (y - y1);
        int tmp2 = (x - x2) * (x - x2) + (y - y2) * (y - y2);
        if(tmp1 < r1 || tmp2 < r2)  
        {
            continue;
        }
        if (tmp1 > tmp2)
        {
            r2 = tmp2;
        }
        else
        {
            r1 = tmp1;
        }
    }
    int ans = r1 + r2;
    std::cout << ans;

    return 0;
}