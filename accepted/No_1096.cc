#include <iostream>

int main()
{
    int L,R;
    int count = 0;
    std::cin >> L >> R;
    for(int i = L;i != R + 1;i++)
    {
        int temp = i;
        while(temp / 10 != 0)
        {
            int digit = temp % 10;
            if(digit == 2)
            {
                count++;
            }
            temp /= 10;
        }
        if(temp == 2)
        {
            count++;
        }
    }
    std::cout << count;

    return 0;
}