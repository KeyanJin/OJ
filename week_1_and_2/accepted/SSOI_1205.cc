#include <vector>
#include <iostream>

class Pole
{
public:
    std::string m_name;
    std::vector<int> m_plates;
    Pole(std::string name, std::vector<int> plates) : m_name(name), m_plates(plates) {}
};

void move(int n, Pole& a, Pole& b, Pole& c)
{
    if (n == 0)
    {
        return;
    }
    move(n - 1, a, c, b);
    auto temp = a.m_plates.back();
    a.m_plates.pop_back();
    b.m_plates.push_back(temp);
    std::cout << a.m_name << "->" << temp << "->" << b.m_name << std::endl;
    move(n - 1, c, b, a);
}
int main()
{
    int n;
    std::cin >> n;
    std::string a, b, c;
    std::cin >> a >> b >> c;
    std::vector<int> _a;
    for (int i = n; i != 0; i--)
    {
        _a.push_back(i);
    }
    std::vector<int> _b = {};
    std::vector<int> _c = {};
    Pole pa = Pole(a, _a);
    Pole pb = Pole(b, _b);
    Pole pc = Pole(c, _c);
    move(n, pa, pb, pc);
}
