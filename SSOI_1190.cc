#include <iostream>
int func(int n)
{
    if(n == 1)
    {
        return 1;
    }
    if(n == 2)
    {
        return 2;
    }
    else
    {
        return func(n - 1) + func(n - 2);
    }
}
int main()
{
    int n = 4;
    int a = func(n);
    std::cout << a;
    return 0;
}