#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    int m;
    std::cin >> m;
    std::vector<int> votes;
    for(int i = 0;i != m;i++)
    {
        int vote;
        std::cin >> vote;
        votes.push_back(vote);
    }
    std::sort(votes.begin(),votes.end());
    for(auto i : votes)
    {
        std::cout << i << " ";
    }
    return 0;
}