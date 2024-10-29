#include <iostream>
#include <vector>
int func(int n)
{   
    if(n == 1)
    {
        return 1;
    }
    else if(n == 2)
    {
        return 2;
    }
    else if(n == 3)
    {
        return 4;
    }
    int arr[n + 1];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i = 3; i != n + 1;i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    return arr[n];
}   
int main()
{

    std::vector<int > results;
    int n;
    while(true)
    {
        std::cin >> n;
        if(n == 0)
        {
            break;
        }
        int result = func(n);
        results.push_back(result);
    }
    for(auto i : results)
    {
        std::cout << i << std::endl;
    }
}