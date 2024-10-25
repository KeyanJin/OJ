#include <iostream>
#include <vector>
class Student
{
public:
    int m_ID;
    int m_total;
    int m_chinese;
    int m_math;
    int m_english;
    Student(){}
    Student(int chinese,int math,int english,int ID) :m_ID(ID),m_total(chinese + math + english),m_chinese(chinese) {}
};
void sort(std::vector<Student> &students)
{
    for(int i = 0;i != students.size();i++)
    {
        for(int j = 0;j < students.size() - i - 1;j++)
        {
            if(students.at(j).m_total < students.at(j + 1).m_total)
            {
                Student temp = students.at(j);
                students.at(j) = students.at(j + 1);
                students.at(j + 1) = temp;
            }else if(students.at(j).m_total == students.at(j + 1).m_total)
            {
                if(students.at(j).m_chinese < students.at(j + 1).m_chinese)
                {
                    Student temp = students.at(j);
                    students.at(j) = students.at(j + 1);
                    students.at(j + 1) = temp;
                }else if(students.at(j).m_chinese == students.at(j + 1).m_chinese)
                {
                    if(students.at(j).m_ID > students.at(j + 1).m_ID)
                    {
                        Student temp = students.at(j);
                        students.at(j) = students.at(j + 1);
                        students.at(j + 1) = temp;
                    }
                }
            }
        }
    }
}
int main()
{
    int n;
    std::vector<Student> students;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        int chinese;
        int math;
        int english;
        int id = i + 1;
        std::cin >> chinese >> math >> english;
        Student student = Student(chinese,math,english,id);
        students.push_back(student);
    }
    sort(students);
    int count = 0;
    for(auto i : students)
    {
        std::cout << i.m_ID << " " << i.m_total << std::endl;
        count++;
        if(count == 5)
        {
            break;
        }
    }
    return 0;
}