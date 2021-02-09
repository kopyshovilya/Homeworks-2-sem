#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

class Course{
const int maxCountStudents = 15;
public:
    bool addStudent(std::string nameStudent)
    {
        if(students.size() == maxCountStudents)
            return 0;
        students.push_back(nameStudent);
        return 1;
    }
    bool delStudent(std::string nameStudent)
    {
        students.erase(std::find(students.begin(), students.end(), nameStudent));
        return 1;
    }
    int count(){
        return students.size();
    }
    std::string namePrepod;
    void printListOfCourse(){
        std::cout << "Teacher: " << namePrepod <<'\n';
        std::cout << "Students:" <<'\n';
        for(auto i:students)
            std::cout << i <<'\n';
    }
private:
    std::vector <std::string> students;

};


int main()
{
    return 0;
}
