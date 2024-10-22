#include <iostream>
#include <vector>
typedef struct Blanket
{
    int x1;
    int x2;
    int y1;
    int y2;
    Blanket(int _x1,int _x2,int _y1,int _y2) : x1(_x1),x2(_x2),y1(_y1),y2(_y2){}
}Blanket;
int main()
{
    int n;
    std::vector<Blanket> blankets;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        int a,b,g,k;
        std::cin >> a >> b >> g >> k;
        Blanket blanket(a,a + g,b,b + k);
        blankets.push_back(blanket);
    }
    int x,y;
    int count = 0;
    std::cin >> x >> y;
    for(int i = n - 1;i >= 0;i--)
    {
        if(x <= blankets.at(i).x2 && x >=  blankets.at(i).x1 && y <=  blankets.at(i).y2 && y >=  blankets.at(i).y1)
        {
            std::cout << i + 1;
            count++;
            break;
        }
    }
    if(count == 0)
    {
        std::cout << -1;
    }
    
    
}