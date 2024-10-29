#include <iostream>

void print_empty(int height,int width,char ch)
{
    for(int i = 0;i != height;i++)
    {
        if(i == 0 || i == height - 1)
        {
            for (int j = 0;j != width;j++) 
            {
                std::cout << ch;
            }
            std::cout << std::endl;
        }
        else
        {
            for(int j = 0;j != width;j++)
            {
                if(j == 0 || j == width - 1)
                {
                    std::cout << ch;
                }
                else
                {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    }
}
void print_com(int height,int width,char ch)
{
    for(int i = 0;i != height;i++)
    {
        for(int j = 0;j != width;j++)
        {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
}
int main()
{
    int height,width,isNotEmpty;
    char ch;
    std::cin >> height >> width >> ch >> isNotEmpty;
    if(isNotEmpty)
    {
        print_com(height, width, ch);
    }
    else
    {
        print_empty(height,width,ch);
    }
    return 0;
}
