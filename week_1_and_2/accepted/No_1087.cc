#include <iostream>
int func(int k)
{
    double sum = 0;
    int n;
    for(n = 1;sum <= k;n++)
    {
        sum += 1.0 / n;
    }
    return n - 1;
}
int main()
{
    int k;
    std::cin >> k;
    int n = func(k);
    std::cout << n;
    return 0;
}