#include <algorithm>
#include <cstdio>
#include <iostream>
#include <setjmp.h>
#include <vector>
int main()
{
    std::vector<double> scores;
    int n;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        double score;
        std::cin >> score;
        scores.push_back(score);
    }
    std::sort(scores.begin(),scores.end());
    double sum = 0;
    for(auto i : scores)
    {
        sum += i;
    }
    double min = scores.at(0);
    double max = scores.at(n - 1);
    std::cout << max << std::endl;
    std::cout << min << std::endl;
    printf("%.2lf",(sum / n));
    return 0;
}