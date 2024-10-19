#include <iostream>

int main(int argc, char const *argv[])
{
    int intVar;
    std::cin >> intVar;
    bool boolVar = intVar;
    int intVar2 = boolVar;
    std::cout << intVar2;
    return 0;
}
