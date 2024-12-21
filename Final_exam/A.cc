#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
int func(int len,int book)
{
    int ans = 0;
    for(int i = 0;i < len;i++)
    {   
        ans += book % 10 * pow(10,i);
        book /= 10;
    }
    return ans;
}
int main()
{
    int n,q;
    std::vector<int > books;
    std::cin >> n >> q;
    for(int i = 0;i < n;i++)
    {
        int tmp;
        std::cin >> tmp;
        books.push_back(tmp);
    }
    std::sort(books.begin(),books.end());
    for(int i = 0;i < q;i++)
    {
        bool flag = true;
        int code,len;
        std::cin >> len >> code;
        for(auto i : books)
        {
            int cmp = func(len,i);
            if(cmp == code)
            {
                std::cout << i << std::endl;\
                flag = false;
                break;
            }
        }
        if(flag)
        {
            std::cout << -1 << std::endl;
        }
    }
    return 0;
}