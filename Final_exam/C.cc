#include <iostream>
int main()
{
    int n;
    std::cin >> n;
    switch (n)
    {
    case 1:
        std::cout << "You were studying " << "Higher mathematics!" << std::endl;
        break;
    case 2:
        std::cout << "You were studying " << "Linear algebra!" << std::endl;
        break;
    case 3:
        std::cout << "You were studying " << "Principle of computer composition!" << std::endl;
        break;
    case 4:
        std::cout << "You were studying " << "Database system concept!" << std::endl;
        break;
    case 5:
        std::cout << "You were playing games!" << std::endl;
        break;
    }
    return 0;
}