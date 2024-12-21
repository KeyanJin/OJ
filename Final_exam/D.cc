#include <algorithm>
#include <iostream>
int main()
{
    long long output = 0;
    long long n, L, R;
    std::cin >> n >> L >> R;
    for(int i = L;i <= R;i++)
    {
        output = std::max(output,i % n);
    }
    std::cout << output << std::endl;
    return 0;
}
