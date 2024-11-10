#include <iostream>
#include <vector>
#include <set>
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums;
    std::set<int> diffs;
    std::set<int> m_diffs;
    for(int i = 0;i != n;i++)
    {
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
    }
    for(int i = 1;i <= n - 1;i++)
    {
        int diff = nums[i] - nums[i - 1];
        diff = diff > 0 ? diff : -diff;
        diffs.insert(diff);
    }
    for(int i = 1;i <= n - 1;i++)
    {
        m_diffs.insert(i);
    }
    std::vector<int> a(diffs.begin(),diffs.end());
    std::vector<int> b(m_diffs.begin(),m_diffs.end());
    if(a.size() != b.size())
    {
        std::cout << "Not jolly";
    }
    else
    {
        for(int i = 0;i < a.size();i++)
        {
            if(a[i] != b[i])
            {
                std::cout << "Not jolly";
                break;
            }
        }
        std::cout << "Jolly";
    }
    
    return 0;
}