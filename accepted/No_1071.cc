#include <iostream>
int fb(int n)
{
    if(n == 0)
    {
        return 0;
    }else if(n == 1 || n == 2)
    {
        return 1;
    }
    int temp,current = 0,next = 1;
    for(int i = 2;i != n + 1;i++)
    {
        temp = current + next;
        current = next;
        next = temp;
    }
    return temp;
    return 0;
}
int main()
{
    int k;
    std::cin >> k;
    std::cout << fb(k);
    return 0;
}