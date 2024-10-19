#include <iostream>
int main()
{
    int n; // 天数
    std::cin >> n;
    int k = 1;
    while((k * (1 + k)) / 2 < n)
    {
        k++;
    }
    k--;
    int sum = n - ((k * (1 + k)) / 2);
    int result = sum * (k + 1) + k * (k + 1) *(2 * k + 1) / 6;
    std::cout << result;
    return 0;
}