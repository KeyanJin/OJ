#include <iostream>
#include <vector>
std::vector<int> arr;

int NUM;
void dfs(int n, int start)
{
    if (n == 0)
    {
        for (auto i = arr.begin(); i != arr.end(); i++)
        {
            if (*i == NUM)
            {
                continue;
            }
            if (i != arr.begin())
            {
                std::cout << "+" << *i;
            }
            else
            {
                std::cout << *i;
            }
        }
        std::cout << std::endl;
        return;
    }
    else
    {
        for (int i = start; i <= n; i++)
        {
            arr.push_back(i);
            dfs(n - i, i);
            arr.pop_back();
        }
    }
}

int main()
{
    std::cin >> NUM;
    dfs(NUM, 1);
    return 0;
}