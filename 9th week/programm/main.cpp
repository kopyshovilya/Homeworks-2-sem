#include <iostream>
#include <map>
#include <list>


class Students {
public:
    Students() {};

    void insert(std::string surname, int mark) {
        marks[surname] = mark;
    }

    void listStudents() {
        for (auto i : marks)
            std::cout << i.first << "\tgets " << i.second << '\t';
    }

    auto find(std::string surname) {
        for (auto i : marks) {
            if (i.first == surname) 
                return i.second;
        }
    }

    std::list<std::string> range(int x) {
        std::list<std::string> l;
        for (auto i : marks) {
            if (i.second == x) {
                l.push_back(i.first);
            }
        }
        return l;
    }

    void standings() {
        std::map<int, std::list<std::string>, std::greater<int>> sortMarks;
        for (auto i : marks) {
            sortMarks[i.second].push_back(i.first);
        }

        for (auto i : sortMarks) {
            std::cout << i.first << ":\t";
            for (auto j : i.second) {
                std::cout << j << '\n';
                std::cout << '\n';
            }
        }
    }
private:
    std::map<std::string, int> marks;
};

int main() {
    Students st;
    st.insert("Ivanov", 30);
    st.insert("Petrov", 10);
    st.insert("Sidorov", 150);

    st.listStudents();
    st.standings();
    return 0;
}