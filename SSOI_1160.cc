#include <cmath>
#include <iostream>
int reverse(int n)
{
    int a = n;
    int new_n = 0;
    int digits = 0;
    while(n / 10 != 0)
    {
        digits++;
        n /= 10;
    }
    while(digits != -1)
    {
        int digit = a % 10;
        new_n += digit * pow(10,digits);
        a /= 10;
        digits--;
    }
    return  new_n;
}
int main()
{
    int n;
    std::cin >> n;
    int digits = reverse(n);
    std::cout << digits;
    return 0;
}