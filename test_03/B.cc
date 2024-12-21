#include <iostream>
#include <vector>

using namespace std;

// 模拟约瑟夫问题
int solveJosephus(int k)
{
    int n = 2 * k; // 总人数是 2k
    int m = 1;     // 从 m=1 开始，逐步增大 m，直到满足条件

    while (true)
    {
        vector<bool> isDead(n, false); // 标记每个人是否已经死了
        int countDead = 0;             // 已经死了的人数
        int currentPos = 0;            // 当前计数的位置
        int badGuysKilled = 0;         // 已经死了的坏人数量

        while (countDead < n - 1)
        { // 直到剩下最后一个人
            // 寻找下一个活着的人
            int steps = 0;
            while (steps < m)
            {
                if (!isDead[currentPos])
                {
                    steps++;
                }
                if (steps < m)
                {
                    currentPos = (currentPos + 1) % n;
                }
            }

            // 杀掉当前的人
            isDead[currentPos] = true;
            countDead++;

            // 如果是坏人，增加坏人死亡数量
            if (currentPos >= k)
            {
                badGuysKilled++;
            }

            // 如果坏人已经全部死亡，且第一个好人没有死，返回当前 m
            if (badGuysKilled == k)
            {
                bool firstGoodManDead = isDead[0];
                if (!firstGoodManDead)
                {
                    return m;
                }
            }

            // 更新当前的位置
            currentPos = (currentPos + 1) % n;
        }

        // 如果这个 m 不符合条件，继续增大 m
        m++;
    }
}

int main()
{
    int k;
    cin >> k; // 输入 k
    int m = solveJosephus(k);
    cout << m << endl; // 输出最小的 m
    return 0;
}
