#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

class Point
{
    public:
        double m_x;
        double m_y;
        double m_z;
        Point() = default;
        Point(double x,double y,double z)
        {
            m_x = x;
            m_y = y;
            m_z = z;
        }
};
int main()
{
    int n;
    std::cin >> n;
    std::vector<Point> points;
    for(int i = 0;i != n;i++)
    {
        double x,y,z;
        std::cin >> x >> y >> z;
        Point p(x,y,z);
        points.push_back(p);
    }
    std::sort(points.begin(),points.end(),[](Point &p1,Point &p2)->bool{
        return p1.m_z < p2.m_z;
    });
    double s = 0;
    for(int i = 1;i <= n - 1;i++)
    {
        double distance = sqrt(pow((points[i].m_x - points[i - 1].m_x),2) +
                                 pow((points[i].m_y - points[i - 1].m_y),2) +
                                 pow((points[i].m_z - points[i - 1].m_z),2));
        s += distance;
    }
    printf("%.3lf" ,s);
    return 0;
}