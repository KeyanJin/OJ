#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for(int i = 0;i != n;i++)
    {
        std::cin >> vec[i];
    }
    std::sort(vec.begin(),vec.end());
    for(auto i : vec)
    {
        if(i % 2 == 0)
        {
            std::cout << i;
            break;
        }
    }
    return 0;
}