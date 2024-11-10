#include <iostream>

int main()
{
    long long n,m;
    std::cin >> n >> m;
    long long square_count = 0;
    long long rectangle_count = 0;
    long long min = n < m ? n : m;
    for(long long i = 0;i != min;i++)
    {
        square_count += (n - i) * (m - i);
    }

    rectangle_count = (n * (n + 1) / 2) * (m * (m + 1) / 2) - square_count;
    std::cout << square_count << " " << rectangle_count;
    return 0;
}