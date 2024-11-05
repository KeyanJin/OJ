#include <iostream>
#include <set>
int main()
{
    int n,m;
    while (std::cin >> n >> m)
    {
        std::set<int > a;
        for(int i = 0;i != n;i++)
        {
            int temp;
            std::cin >> temp;
            a.insert(temp);
        }
        for(int i = 0;i != m;i++)
        {
            int temp;
            std::cin >> temp;
            a.insert(temp);
        }
        for(auto i : a)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}