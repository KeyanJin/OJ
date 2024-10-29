#include <cstdio>
#include <iostream>

int main()
{   
    int x,n;
    std::cin >> x >> n;
    double p = (double)x;
    for(int i = 0;i < n;i++)
    {
        p *= 1.001;
    }
    printf("%.4lf",p);
    return 0;
}