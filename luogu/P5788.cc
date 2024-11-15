#include <iostream>
#include <stack>
#include <vector>
int main()
{
    std::stack<int> m_stack;
    std::vector<int> input;
    std::vector<int> output;
    int n;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        int temp;
        std::cin >> temp;
        input.push_back(temp);
    }
    for(int i = n - 1;i >= 0;i--)
    {
        for(;;)
        {
            
        }
    }
    return 0;
}