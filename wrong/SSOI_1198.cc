#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
void split(std::string str,std::vector<std::string > &strs)
{
    std::istringstream record(str);
    std::string temp;
    while(record >> temp)
    {
        strs.push_back(temp);
    }
}
int main()
{
    std::stack<double > m_stack;
    std::string str;
    std::stack<int > nums;
    std::getline(std::cin,str);
    std::vector<std::string > strs;
    split(str,strs);
    for(int i = 0;i != strs.size();i++)
    {
        
        try {
            std::string temp = strs.at(i);
            m_stack.push(std::stod(temp));
        } 
        catch (std::invalid_argument & e) 
        {
            continue;
        }
        
    }
    for(int i = 0;i != strs.size();i++)
    {
        if(strs.at(i) == "*" || strs.at(i) == "\\*")
        {
            double temp1,temp2;
            temp1 = m_stack.top();
            m_stack.pop();
            temp2 = m_stack.top();
            m_stack.pop();
            m_stack.push(temp2 * temp1);
        }else if(strs.at(i) == "+")
        {
            double temp1,temp2;
            temp1 = m_stack.top();
            m_stack.pop();
            temp2 = m_stack.top();
            m_stack.pop();
            m_stack.push(temp2 + temp1);
        }else if(strs.at(i) == "-")
        {
            double temp1,temp2;
            temp1 = m_stack.top();
            m_stack.pop();
            temp2 = m_stack.top();
            m_stack.pop();
            m_stack.push(temp1 - temp2);
        }else if(strs.at(i) == "/")
        {
            double temp1,temp2;
            temp1 = m_stack.top();
            m_stack.pop();
            temp2 = m_stack.top();
            m_stack.pop();
            m_stack.push(temp1 / temp2);
        }
    }
    std::cout << m_stack.top();
    return 0;
}