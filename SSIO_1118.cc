#include <iostream>
#include <vector>
class Point
{
    public:
    Point(int _x,int _y) :x(_x),y(_y){} 
    int x;
    int y;
};
class Blanket
{
    public:
    Blanket(Point _p1,Point _p2,Point _p3,Point _p4) : p1(_p1),p2(_p2),p3(_p3),p4(_p4){}
    Point p1;
    Point p2;
    Point p3;
    Point p4;
};
int main()
{
    int n;
    std::cin >> n;
    std::vector<Blanket> blankets;
    for(int i = 0;i != n;i++)
    {
        int a,b,g,k;
        std::cin >> a >> b >> g >> k;
        Point p1 = Point(a,b);
        Point p2 = Point(g + a,b);
        Point p3 = Point(a + g,b + k);
        Point p4 = Point(a,b + k);
        Blanket blanket = Blanket(p1,p2,p3,p4);
        blankets.push_back(blanket);
    }
    int x,y;
    int count = 0;
    std::cin >> x >> y;
    for(auto i : blankets)
    {
        if(x >= i.p1.x && x <= i.p2.x && y <= i.p3.y && y >= i.p1.y )
        {
            count++;
        }
    }
    if(count == 0)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << count;
    }
    return 0;
}