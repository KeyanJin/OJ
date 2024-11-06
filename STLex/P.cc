#include <iostream>
#include <string>
int main()
{
    int n;
    char op;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        std::string str = "";
        int result = 0;
        int num1,num2;
        if(std::cin >> num1)
        {
            std::cin >> num2;
            switch (op) 
            {
                case 'a':
                    result = num1 + num2;
                    str += std::to_string(num1) + "+" + std::to_string(num2)+ "=" + std::to_string(result);
                    std::cout << str << std::endl;
                    std::cout << result << std::endl;
                    break;
                case 'b':
                    result = num1 - num2;
                    str += std::to_string(num1) + "-" + std::to_string(num2)+ "=" + std::to_string(result);
                    std::cout << str << std::endl;
                    std::cout << result << std::endl;
                    break;
                case 'c':
                    result = num1 * num2;
                    str += std::to_string(num1) + "*" + std::to_string(num2)+ "=" + std::to_string(result);
                    std::cout << str << std::endl;
                    std::cout << result << std::endl;
                    break;
            }
        }
        else
        {
            std::cin.ignore();
            std::cin >> op >> num1 >> num2;
            switch (op) 
            {
                case 'a':
                    result = num1 + num2;
                    str += std::to_string(num1) + "+" + std::to_string(num2)+ "=" + std::to_string(result);
                    std::cout << str << std::endl;
                    std::cout << result << std::endl;
                    break;
                case 'b':
                    result = num1 - num2;
                    str += std::to_string(num1) + "-" + std::to_string(num2)+ "=" + std::to_string(result);
                    std::cout << str << std::endl;
                    std::cout << result << std::endl;
                    break;
                case 'c':
                    result = num1 * num2;
                    str += std::to_string(num1) + "*" + std::to_string(num2)+ "=" + std::to_string(result);
                    std::cout << str << std::endl;
                    std::cout << result << std::endl;
                    break;
            }
        }
    }
    return 0;
}