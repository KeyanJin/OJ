#include <iostream>
#include <vector>

bool isPrime(int num)
{
    if(num <= 1)
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
            return false;
    }
    return true;
}
int main()
{
    std::vector<int> primes;
    int n;
    int num = 2;
    std::cin >> n;
    while((primes.size()) != n)
    {
        if(isPrime(num))
        {
            primes.push_back(num);
        }
        num++;
    }
    std::cout << primes.back();
    return 0;
}