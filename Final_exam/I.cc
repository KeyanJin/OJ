#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
struct pos
{
    int x;
    int y;
};
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int main()
{
    std::vector<std::pair<int,int>> vec;
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    vec.push_back(std::make_pair(x1,y1));
    vec.push_back(std::make_pair(x2,y2));
    std::string wards;
    std::cin >> wards;
    pos bot1 = {x1, y1};
    pos bot2 = {x2, y2};
    std::map<char, int> mp = {{'U', 0}, {'R', 1}, {'L', 2}, {'D', 3}};
    for (auto i : wards)
    {
        for (auto j : mp)
        {
            if (j.first == i)
            {
                int x_ = bot1.x + dx[j.second];
                int y_ = bot1.y + dy[j.second];
                vec.push_back(std::make_pair(x_,y_));
                bot1 = {x_,y_};
            }
        }
    }
    for (auto i : wards)
    {
        for (auto j : mp)
        {
            if (j.first == i)
            {
                int x_ = bot2.x + dx[j.second];
                int y_ = bot2.y + dy[j.second];
                if(std::find(vec.begin(),vec.end(),std::make_pair(x_, y_)) != vec.end())
                {
                    std::cout << "Explosion" << std::endl;
                    goto out_loop;
                }
                bot2 = {x_,y_};
            }
        }
    }
    std::cout << "Safe" << std::endl;
    out_loop:
    return 0;
}