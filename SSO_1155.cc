#include <iostream>
bool is_prime(int n)
{
    if(n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for(int i = 5;i * i <= n;i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}
bool is_huiwen(int n)
{
    int one = n % 10;
    int ten = n / 10 % 10;
    int han = n / 100;
    int new_n = one * 100 + ten * 10 + han;
    if(new_n == n)
    {
        return true;
    }
    else {
        return false;
    }
}
int main()
{
    for(int i = 100;i != 1000;i++)
    {
        if(is_huiwen(i) && is_prime(i))
        {
            std::cout << i << std::endl;
        }
    }
}