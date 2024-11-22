#include <algorithm>
#include <iostream>

int excer_nums[4];

int m_time[4][200];

int LBrain = 0;
int RBrain = 0;

int min_time = 1e8;
int ans = 0;
void dfs(int sub,int ex)
{
    if(ex >= excer_nums[sub])
    {
        min_time = std::min(std::max(LBrain , RBrain),min_time);
        return;
    }
    LBrain += m_time[sub][ex];
    dfs(sub,ex + 1);
    LBrain -= m_time[sub][ex];
    RBrain += m_time[sub][ex];
    dfs(sub,ex + 1);
    RBrain  -= m_time[sub][ex];
}

int main()
{
    int s1,s2,s3,s4;
    std::cin >> s1 >> s2 >> s3 >> s4;
    excer_nums[0] = s1;
    excer_nums[1] = s2;
    excer_nums[2] = s3;
    excer_nums[3] = s4;
    for(int i = 0;i != 4;i++)
    {
        for(int j = 0;j != excer_nums[i];j++)
        {
            std::cin >> m_time[i][j];
        }
    }
    for(int i = 0;i != 4;i++)
    {
        LBrain = 0;
        RBrain = 0;
        min_time = 1e8;
        dfs(i,0);
        ans += min_time;
    }
    std::cout << ans;
    // for(int i = 0;i != 4;i++)
    // {
    //     for(int j = 0;j != excer_nums[i];j++)
    //     {
    //         std::cout << m_time[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return 0;
}