#include <vector>
#include <string>
#include <iostream>

typedef struct directory 
{
    struct directory * pre;
    std::string name;
    std::vector<struct directory *> dirs;
    std::vector<std::string> files;
}directory;
void CD(directory * cur,const std::string name,directory * root)
{   
    if(name == "/")
    {
        cur = root;
        std::cout << "success" << std::endl;
    }
    else if(name == "..")
    {
        cur = cur->pre;
        std::cout << "success" << std::endl;
    }
    for(auto i : cur->dirs)
    {
        if(i->name == name)
        {
            directory * temp = cur;
            cur = i;
            cur->pre = temp;
            std::cout << "success" << std::endl;
            return;
        }
        else
        {
            std::cout << "no such directory" << std::endl;
        }
    }
}
void MD(directory * cur,const std::string name)
{
    for(auto i : cur->dirs)
    {
        if(i->name == name)
        {
            std::cout << "directory already exist" << std::endl;
            return;
        }
        else
        {
            directory * temp;
            temp->name = name;
            temp->dirs = {};
            temp->files = {};
            i->dirs.push_back(temp);
            std::cout << "success" << std::endl;
        }
    }
}
void RD(directory * cur,const std::string name)
{
    for(auto i = cur->dirs.begin();i != cur->dirs.end();i++)
    {
        if((*i)->name == name)
        {
            if((*i)->dirs.size() == 0 && (*i)->files.size() == 0)
            {
                cur->dirs.erase(i);
                std::cout << "success" << std::endl;
                return;
            }
            else
            {
                std::cout << "can not delete the directory" << std::endl;
                return;
            }
        }
    }
    std::cout << "can not delete the directory" << std::endl;
}
void CREATE(directory * cur,const std::string name)
{
    for(auto i : cur->files)
    {
        if(i == name)
        {
            std::cout << "file already exist" << std::endl;
            return;
        }
    }
    cur->files.push_back(name);
    std::cout << "success" << std::endl;
}
void DELETE(directory * cur,const std::string name)
{
    for(auto i = cur->files.begin();i != cur->files.end();i++)
    {
        if((*i) == name)
        {
            cur->files.erase(i);
            std::cout << "success" << std::endl;
        }
    }
    std::cout << "no such file" << std::endl;
}
int main()
{
    directory * current;
    directory * root;
    current = root;
    root->files = {};
    root->dirs = {};
    std::string oper;
    std::string name;
    while(std::cin >> oper >> name)
    {
        if(oper == "CD")
        {
            CD(current,name,root);
        }
        else if(oper == "MD")
        {
            MD(current,name);
        }
        else if(oper == "RD")
        {
            RD(current,name);
        }
        else if(oper == "CREATE")
        {
            CREATE(current, name);
        }
        else if(oper == "DELETE")
        {
            DELETE(current,name);
        }
    }   
}