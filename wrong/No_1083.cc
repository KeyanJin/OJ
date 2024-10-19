#include <iostream>

int main()
{
    unsigned long long a,b;
    std::cin >> a >> b;
    unsigned long long days = 1;
    for(int i = 0;i != b;i++)
    {
        days *= a;
    }
    unsigned long long day = days % 7;
    switch (day) 
    {
        case 1:
            std::cout << "Monday";
            break;
        case 2:
            std::cout << "Tuesday";
            break;
        case 3:
            std::cout << "Wednesday";
            break;
        case 4:
            std::cout << "Thursday";
            break;
        case 5:
            std::cout << "Friday";
            break;
        case 6:
            std::cout << "Saturday";
            break;
        case 0:
            std::cout << "Sunday";
            break;
    }
    return 0;
}