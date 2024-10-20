#include <iostream>
int main()
{
    int a,b,n;
    std::cin >> a >> b >> n;
    int digit = a % b;
    for(int i = 0;i != n;i++)
    {
        digit *= 10;
        digit %= b;
    }
    std::cout << digit * 10 / b;
    return 0;
}