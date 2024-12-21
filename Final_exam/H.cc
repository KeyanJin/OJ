#include <iostream>
#include <vector>
bool judge(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] > vec[i + 1])
        {
            return false;
        }
    }
    return true;
}
int my_sort(std::vector<int> &vec)
{
    if (judge(vec))
    {
        return 0;
    }
    int min_index = 0;
    for (int j = 0; j < vec.size(); j++)
    {
        if (vec[min_index] > vec[j])
        {
            min_index = j;
        }
    }
    int max_index = 0;
    for (int j = 0; j < vec.size(); j++)
    {
        if (vec[max_index] < vec[j])
        {
            max_index = j;
        }
    }
    if (max_index == vec.size() - 1)
    {
        if (min_index == 0)
        {
            return 1;
        }
        else
        {
            return 1;
        }
    }
    else if (max_index == 0)
    {
        if (min_index == vec.size() - 1)
        {
            return 3;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        if (min_index == 0)
        {
            return 1;
        }
        else if (min_index == vec.size() - 1)
        {
            return 2;
        }
        else
        {
            return 2;
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        vec.push_back(tmp);
    }
    int ans = my_sort(vec);
    std::cout << ans;
    return 0;
}