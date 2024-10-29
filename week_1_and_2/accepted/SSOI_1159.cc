#include <iostream>
int fb(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    if(n == 2)
    {
        return 1;
    }
    else
    {
        return fb(n - 1) + fb(n - 2);
    }
}
int main()
{
    int n;
    std::cin >> n;
    int fb_n = fb(n - 1);
    std::cout << fb_n;
}