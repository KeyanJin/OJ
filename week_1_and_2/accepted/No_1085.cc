#include <iostream>

#include <cmath>
int main()
{
    double n;
    std::cin >> n;
    double ten = pow(0.5,10) * n; 
    double sum = ((n / 2) * (1 - pow(0.5,10))) / 0.5 * 2 + n - ten * 2;
    std::cout << sum << std::endl;
    std::cout << ten; 

    return 0;
}