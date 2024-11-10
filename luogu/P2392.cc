#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int s1,s2,s3,s4;
    std::vector<int> v_s1(s1 + 1);
    std::vector<int> v_s2(s2 + 1);
    std::vector<int> v_s3(s3 + 1);
    std::vector<int> v_s4(s4 + 1);
    std::cin >> s1 >> s2 >> s3 >> s4;
    for(int i = 0;i != s1;i++)
    {
        int time;
        std::cin >> time;
        v_s1.push_back(time);
    }
    for(int i = 0;i != s2;i++)
    {
        int time;
        std::cin >> time;
        v_s1.push_back(time);
    }
    for(int i = 0;i != s3;i++)
    {
        int time;
        std::cin >> time;
        v_s1.push_back(time);
    }
    for(int i = 0;i != s4;i++)
    {
        int time;
        std::cin >> time;
        v_s1.push_back(time);
    }
    std::sort(v_s1.begin(),v_s1.end());
    std::sort(v_s2.begin(),v_s2.end());
    std::sort(v_s3.begin(),v_s3.end());
    std::sort(v_s4.begin(),v_s4.end());
    std::vector<int> one;
    std::vector<int> two;
    std::vector<int> three;
    std::vector<int> four;
    for(int i = 0;i != v_s1.size();i++)
    {
        one[i]
    }
    return 0;
}