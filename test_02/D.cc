#include <iostream>
#include <vector>

bool is_prime(int n)
{
    if(n == 2 || n == 3)
    {
        return true;
    }
    else if(n == 1)
    {
        return false;
    }
    else if(n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    else
    {
        for(int i = 5;i * i <= n;i += 6)
        {
            if(n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    int n,q;
    std::cin >> n >> q;
    std::vector<int> primes;
    for(int i = 2;i <= n;i++)
    {
        if(is_prime(i))
        {
            primes.push_back(i);
        }
    }
    for(int i = 0;i != q;i++)
    {
        int index;
        std::cin >> index;
        std::cout << primes[index - 1] << std::endl;
    }
    return 0;
}