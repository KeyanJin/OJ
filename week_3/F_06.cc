#include <iostream>
int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for(int i = 0;i != n;i++)
    {
        int temp;
        std::cin >> temp;
        arr[i] = temp;
    }
    for(int i = 0;i != n;i++)
    {
        int count = 0;
        if(i == 0)
        {
            std::cout << 0 << " ";
            continue;
        }
        for(int j = 0;j < i;j++)
        {
            if(arr[j] < arr[i])
            {
                count++;
            }
        }
        std::cout << count << " ";
    }
    return 0;
}