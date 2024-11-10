#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    int n;
    int m;
    std::vector<int > s;
    std::cin >> n >> m;

    for(int i = 0;i != m;i++)
    {
        int temp;
        std::cin >> temp;
        s.push_back(temp);
    }
    std::sort(s.begin(),s.end());
    for(auto i : s)
    {
        std::cout << i << " ";
    }
    return 0;
}