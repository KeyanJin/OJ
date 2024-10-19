#include <iostream>
int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        int result = 1;
        for(int i = 1;i != n + 1;i++)
        {
            result *= i;
        }
        return result;
    }
}
int main()
{
    int n;
    int sum = 0;
    std::cin >> n;
    for(int i = 1;i != n + 1;i++)
    {
        sum += factorial(i);
    }
    std::cout << sum;
    return 0;
}