#include <iostream>
#include <vector>
int main()
{
    int L,M;
    std::cin >> L >> M;
    std::vector<int> trees(L + 1,1);
    for(int i = 0;i != M;i++)
    {
        int end;
        int start;
        std::cin >> start >> end;
        for(int i = start;i != end + 1;i++)
        {
            if(trees.at(i) == 1)
            {
                trees.at(i ) = 0;
            }
        }
    }
    int count = 0;
    for(auto i : trees)
    {
        if(i == 1)
        {
            count++;
        }
    }
    std::cout << count;
    return 0;
}