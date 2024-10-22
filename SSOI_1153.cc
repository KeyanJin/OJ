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
int main()
{
    for(int i = 10;i != 100;i++)
    {
        if(is_prime(i))
        {
            int one = i % 10;
            int ten = i / 10;
            int new_i = one * 10 + ten;
            if(is_prime(new_i))
            {
                std::cout << i << std::endl; 
            }
        }
    }
    return 0;
}