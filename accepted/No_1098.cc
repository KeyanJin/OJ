#include <iostream>
bool isPrime(int num)
{
    if(num == 1)
    {
        return false;
    }else if(num == 2 || num == 3)
    {
        return true;
    }else if(num % 2 == 0 || num % 3 == 0)
    {
        return false;
    }
    for(int i = 5;i * i <= num;i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    int even = 0;
    std::cin >> n;
    for(int i = 2;i <= n / 2;i++)
    {
        if(isPrime(i) && n % i == 0)
        {
            even = n / i;
            if(isPrime(even))
            {
                std::cout << even;
                break;
            }
        }
    }
    return 0;
}