#include <cmath>
#include <cstdio>
#include <iostream>

double cal_mon(double pri, double rate, int mon)
{
    return pri * (rate * pow(1 + rate, mon)) / (pow(1 + rate, mon) - 1);
}
double cal_rate(double p, double r, int n)
{
    double r_min = 0.0;
    double r_max = 5.0;
    while ((r_max - r_min) > 1e-6)
    {
        double r_mid = (r_min + r_max) / 2.0;
        double tmp = cal_mon(p, r_mid, n);
        if (tmp > r)
        {
            r_max = r_mid;
        }
        else
        {
            r_min = r_mid;
        }
    }
    return (r_min + r_max) / 2.0;
}
int main()
{
    double w0, w, m;
    std::cin >> w0 >> w >> m;
    double r = cal_rate(w0, w, m);
    r *= 100;
    printf("%.1lf\n", r);
    return 0;
}