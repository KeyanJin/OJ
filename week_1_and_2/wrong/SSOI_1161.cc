#include <iostream>
#include <map>
#include <string>

void func(std::map<int, std::string> chars,int x,int m,std::string &result)
{
    int quo = x / m;
    int mod = x % m;
    if(quo == 0)
    {
        auto temp = chars.find(mod);
        result += temp->second;
        return;
    }
    func(chars,quo,m,result);
    auto temp = chars.find(mod);
    result += temp->second;
}

int main()
{
    std::map<int, std::string> chars = {{0,"0"},{1,"1"},{2,"2"},
    {3,"3"},{4,"4"},{5,"5"},{6,"6"},{7,"7"},{8,"8"},{9,"9"},{10,"A"},
    {11,"B"},{12,"C"},{13,"D"},{14,"E"},{15,"F"}};
    int x;
    int m;
    std::cin >> x >> m;
    std::string str;
    func(chars, x,  m, str);
    std::cout << str;
    return 0;
}