#include <iostream>
#include <queue>
int main()
{
    int n;
    std::cin >> n;
    std::vector<std::queue<int >> vec;
    for(int i = 0;i != n;i++)
    {
        int m;
        std::cin >> m;
        int flag = 2;
        std::queue<int> mque;
        for(int ii = 1;ii <= m;ii++)
        {
            mque.push(ii);
        }
        for(;mque.size() > 3;)
        {
            int size = mque.size();
            if(flag == 2)
            {
                for(int iii = 0;iii < size / 2;iii++)
                {
                    int temp = mque.front();
                    mque.pop();
                    mque.push(temp);
                    mque.pop();
                }
                flag = 3;
                if(size & 1)
                {
                    int temp = mque.front();
                    mque.pop();
                    mque.push(temp);
                }
            }
            else if(flag == 3)
            {
                for(int iii = 0;iii < size / 3;iii++)
                {
                    int temp = mque.front();
                    mque.pop();
                    mque.push(temp);
                    temp = mque.front();
                    mque.pop();
                    mque.push(temp);
                    mque.pop();
                }
                flag = 2;
                if(size % 3 != 0)
                {
                    if(size % 3 == 1)
                    {
                        int temp = mque.front();
                        mque.pop();
                        mque.push(temp);
                    }
                    else if(size % 3 == 2)
                    {
                        int temp = mque.front();
                        mque.pop();
                        mque.push(temp);
                        temp = mque.front();
                        mque.pop();
                        mque.push(temp);
                    }
                    
                }
            }
        }
        vec.push_back(mque);
    }
    for(auto i : vec)
    {
        while(!i.empty())
        {
            std::cout << i.front() << " ";
            i.pop();
        }
        std::cout << std::endl;
    }
    return 0;
}
