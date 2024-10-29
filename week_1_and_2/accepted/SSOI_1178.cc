#include <iostream>
#include <vector>
class Student
{
    public:
    std::string m_name;
    int m_score;
    Student(std::string name,int score) : m_score(score),m_name(name){}
    Student(){}
};
int main()
{
    int n;
    std::vector<Student> students;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        std::string name;
        int score;
        std::cin >> name >> score;
        Student student = Student(name,score);
        students.push_back(student);
    }
    for(int i = 0;i != n;i++)
    {
        for(int j = 0;j < n - i - 1;j++)
        {
            if(students.at(j).m_score < students.at(j + 1).m_score)
            {
                Student temp = students.at(j);
                students.at(j) = students.at(j + 1);
                students.at(j + 1) = temp;
            }else if(students.at(j).m_score == students.at(j + 1).m_score)
            {
                if(students.at(j).m_name > students.at(j + 1).m_name)
                {
                    Student temp = students.at(j);
                    students.at(j) = students.at(j + 1);
                    students.at(j + 1) = temp;
                }
            }
        }
    }
    for(auto i : students)
    {
        std::cout << i.m_name << " " << i.m_score << std::endl;
    }
    return 0;
}