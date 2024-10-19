#include <iostream>
int main()
{
    int n;
    int count = 0;
    std::cin >> n;
    for(int i = 1;i != n + 1;i++)
    {
        int temp = i;
        while (temp / 10 != 0)
        {
            int digit = temp % 10;
            if(digit == 1)
            {
                count++;
            }
            temp /= 10;
        }
        if(temp == 1)
        {
            count++;
        }
    }
    std::cout << count;

}