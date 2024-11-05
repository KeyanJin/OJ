#include <iostream>
#include <vector>
#include <algorithm> 

void quickSort(std::vector<int>& m_vec, int left, int right) {
    if (left >= right)
    {
        return; 
    } 
    int mid = m_vec[left + (right - left) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (m_vec[i] < mid)
        {
            i++; 
        }
            
        while (m_vec[j] > mid) 
        {
            j--;
        } 
        if (i <= j) 
        {
            std::swap(m_vec[i], m_vec[j]); 
            i++;
            j--;
        }
    }
    if (left < j) 
    {
        quickSort(m_vec, left, j);
    }
    if (i < right) 
    {
        quickSort(m_vec, i, right);
    }
}
void quickSort(std::vector<int>& m_vec) {
    if (m_vec.empty()) 
    {
        return;
    }
    quickSort(m_vec, 0, m_vec.size() - 1);
}
int main() 
{
    std::vector<int> m_vec;
    int n;
    int k;
    std::cin >> n >> k;
    for(int i = 0;i != n;i++)
    {
        int temp;
        std::cin >> temp;
        m_vec.push_back(temp);
    }
    quickSort(m_vec);
    std::cout << m_vec[k];
    return 0;
}