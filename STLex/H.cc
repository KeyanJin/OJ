#include <iostream>
#include <queue>
#include <vector>
long long Max(long long a,long long b,long long c)
{
    if(a > b)
    {
        if(a > c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if(b > c)
        {
            return b;
        }
        else 
        {
            return c;
        }
    }
}
long long Min(long long a,long long b,long long c)
{
    if(a < b)
    {
        if(a < c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if(b < c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}
int main()
{
    unsigned long n,k;
    std::queue<long long> m_que;
    std::vector<long long> mins;
    std::vector<long long> maxs;
    std::cin >> n >> k;
    for(unsigned long i = 0;i != n;i++)
    {
        long long temp;
        std::cin >> temp;
        m_que.push(temp);
    }
    for(unsigned long i = 0;i != n - k + 1;i++)
    {
        std::queue<long long> copy_que = m_que;
        long long num1 = copy_que.front();
        copy_que.pop();
        long long num2 = copy_que.front();
        copy_que.pop();
        long long num3 = copy_que.front();
        m_que.pop();
        m_que.push(num1);
        mins.push_back(Min(num1, num2, num3));
        maxs.push_back(Max(num1, num2, num3));
    }
    for(auto i : mins)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for(auto i : maxs)
    {
        std::cout << i << " ";
    }
    return 0;
}