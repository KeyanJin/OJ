#include <cmath>
#include <iostream>

int main()
{
    int n;
    double time;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        double x,y;
        int persons;
        std::cin >> x >> y >> persons;
        double l = sqrt(pow(x,2) + pow(y,2));
        time += (l/50) * 2 + persons * 1 + persons * 0.5;
    }
    std::cout << (int)time + 1;


    return 0;
}