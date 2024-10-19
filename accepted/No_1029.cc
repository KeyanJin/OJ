#include <iostream>


int main()
{
    double a,b;
    std::cin >> a >> b;
    int k = a / b;
    double mod = a - b * k;
    std::cout << mod;
    return 0;
}