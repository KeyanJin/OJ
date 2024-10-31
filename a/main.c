#include <stdio.h>

// 递归调用函数
int fb(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else if(n == 2)
    {
        return 1;
    }
    else
    {
        return fb(n - 1) + fb(n - 2);
    }
}
// 尾递归调用
int fb_tail(int n,int temp1,int temp2)
{
    if(n == 1)
    {
        return 1;
    }
    else if(n == 2)
    {
        return 1;
    }
    else
    {
        return fb_tail(n - 1,temp2,temp1 + temp2);
    }
}
