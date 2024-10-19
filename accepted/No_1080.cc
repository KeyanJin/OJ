#include <iostream>

int min(int a,int b,int c)
{
    int min = a;
    if(a > b)
    {
        min = b;
    }
    if(min > c)
    {
        return c;
    }
    else {
        return min;
    }
}
int main()
{
	int a,b,c;
	std::cin >> a >> b >> c;
    for(int i = 2;i <= min(a,b,c) / 2;i++)
    {
        int x = a % i;
        int y = b % i;
        int z = c % i;
        if(x == y && y == z)
        {
            std::cout << i;
            break;
        }
    }
	return 0;
}
