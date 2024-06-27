#include <bits/stdc++.h>
using namespace std;

class Student_Info {
friend bool compare(Student_Info, Student_Info);
private:
    string name;
    double grade;

public:
    Student_Info(string name, double grade) {
        this->name = name;
        this->grade = grade;
    }

    string get_name() {
        return this->name;
    }

};

bool compare(Student_Info a, Student_Info b) {
    return a.grade < b.grade;
}

int main() {
    vector<Student_Info> students = {
        Student_Info("John", 8.5),
        Student_Info("Bob", 7.5),
        Student_Info("Jane", 9.5),
    };
    sort(students.begin(), students.end(), compare);
    for (auto&& student : students) {
        cout << student.get_name() << endl;
    }
}
