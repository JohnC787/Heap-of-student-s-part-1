#include <iostream>
#include <vector>
#include <fstream>
#include "student.h"

void loadStudents(std::vector<Student*>& students);
void printStudents(std::vector<Student*>& students);
void showStudentNames(std::vector<Student*>& students);
void findStudent(std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);
std::string menu();

int main() {

    std::vector<Student*> students;

    loadStudents(students);

    std::string choice;

    do {

        choice = menu();

        if(choice == "1")
            showStudentNames(students);

        else if(choice == "2")
            printStudents(students);

        else if(choice == "3")
            findStudent(students);

    } while(choice != "0");

    delStudents(students);

    return 0;
}

void loadStudents(std::vector<Student*>& students) {

    std::ifstream file("students.csv");
    std::string line;

    while(getline(file, line)) {

        Student* s = new Student(line);

        students.push_back(s);
    }

    file.close();
}

void printStudents(std::vector<Student*>& students) {

    for(Student* s : students)
        s->printDetails();
}

void showStudentNames(std::vector<Student*>& students) {

    for(Student* s : students)
        s->printSummary();
}

void findStudent(std::vector<Student*>& students) {

    std::string search;

    std::cout << "last name of student: ";
    std::cin >> search;

    for(Student* s : students) {

        if(s->getLastName().find(search) != std::string::npos)
            s->printDetails();
    }
}

void delStudents(std::vector<Student*>& students) {

    for(Student* s : students)
        delete s;

    students.clear();
}

std::string menu() {

    std::string choice;

    std::cout << "\n0) quit\n";
    std::cout << "1) print all student names\n";
    std::cout << "2) print all student data\n";
    std::cout << "3) find a student\n\n";

    std::cout << "please choose 0-3: ";

    std::cin >> choice;

    return choice;
}
