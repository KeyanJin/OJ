#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    std::map<char, int> m_map;
    char temp;
    while(std::cin >> temp)
    {
        if(temp <= 'Z' && temp >= 'A')
        {
            m_map[temp]++;
        }
    }

    // Find the maximum count
    int max = 0;
    for(const auto& pair : m_map)
    {
        if(pair.second > max)
        {
            max = pair.second;
        }
    }

    // Create a 2D array for the histogram
    std::vector<std::vector<char>> arr(max, std::vector<char>(26, ' '));

    // Fill the histogram array
    for(const auto& pair : m_map)
    {
        char letter = pair.first;
        int count = pair.second;
        for(int i = 0; i < count; ++i)
        {
            arr[max - 1 - i][letter - 'A'] = '*';
        }
    }

    // Print the histogram
    for(int i = 0; i < max; ++i)
    {
        for(int j = 0; j < 26; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Print the letters
    for(char c = 'A'; c <= 'Z'; ++c)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}