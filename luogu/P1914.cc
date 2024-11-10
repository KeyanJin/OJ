#include <string>
#include <iostream>
int main()
{
    int n;
    std::string be;
    std::cin >> n;
    std::cin >> be;
    for(auto &i : be)
    {
        i = (i - 'a' + n) % 26 + 'a';
    }
    std::cout << be;
    return 0;

}