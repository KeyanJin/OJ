#include <iostream>
#include <stack>
#include <vector>

int main()
{
    int n;
    std::string a,b;
    while(std::cin >> n >> a >> b)
    {
        std::stack<char> m_sta;
        std::vector<int> ans;
        int i = 0;
        int j = 0;
        while(i < n)
        {
            m_sta.push(a[i]);
            ans.push_back(1);
            while(!m_sta.empty() && m_sta.top() == b[j])
            {
                m_sta.pop();
                j++;
                ans.push_back(0);
            }
            i++;
        }
        if(j < n)
        {
            std::cout << "No." << std::endl;
        }
    }
    return 0;
}