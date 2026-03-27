#include <iostream>
#include <vector>
#include "student.h"
#include "person.h"
#include <algorithm>
using namespace std;
vector<student> students;
int find_student(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].get_id() == id) {
            return i;
        }
    }
    return -1;
}

void addstudent() {
    int id;
    int age;
    string name;
    double gpa;

    cout << "enter student ID: \n";
    cin >> id;

    if (find_student(id) != -1) {
        cout << "ID is already exist\n";
        return;
    }

    cout << "enter the student name\n";
    cin.ignore();
    getline(cin, name);

    cout << "enter GPA \n";
    cin >> gpa;
    if (gpa < 0 || gpa > 4.0) {
        cout << "gpa not valid\n";
        return;
    }

    cout << "enter student's age\n";
    cin >> age;

    student s(name, age, gpa, id);
    students.push_back(s);

    cout << "student added successfully!\n";
}
void removestudent() {
    int id;
    cout << "enter student ID: \n";
    cin >> id;
    int index = find_student(id);
    if (index == -1) {
        cout << "user not found\n";
        return;
    }
    students.erase(students.begin() + index);
    cout << "student removed successfully\n";
}

void search_student() {
    int id;
    cout << "enter student ID: \n";
    cin >> id;
    if (find_student(id) == -1) {
        cout << "student is not found\n";
        return;
    }
    int index = find_student(id);

    students[index].display();
}

void display_all() {
    if (students.empty()) {
        cout << "NO students in the system \n";
    }
    for (auto& x : students) {
        x.display();
    }

    cout << "total: " << students.size() << "\n";
}

void enrollcourse() {
    int id;
    string course;
    cout << "enter student ID: \n";
    cin >> id;

    if (find_student(id) == -1) {
        cout << "student is not found\n";
        return;
    }
    int index = find_student(id);

    cout << "enter the course name\n";
    cin >> course;

    students[index].enroll_course(course);

}


void studentcourses() {

    int id;
    cout << "enter student ID: \n";
    cin >> id;

    if (find_student(id) == -1) {
        cout << "student is not found\n";
        return;
    }
    int index = find_student(id);
    cout << "courses for " << students[index].get_name() << "\n";
    students[index].getall_courses();
}



void sortstudents() {
    sort(students.begin(), students.end(), [](student a, student b) {
        return a.get_gpa() > b.get_gpa();
        });

    cout << "students sorted by GPA\n";
    for (int i = 0; i < students.size(); i++) {
        students[i].display();
    }
}

int main() {

    int choice;


    do {
        cout << "\n=============================" << endl;
        cout << "  Student Management System  " << endl;
        cout << "=============================" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Remove Student" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Display All Students" << endl;
        cout << "5. Enroll Student in Course" << endl;
        cout << "6. Show Student Courses" << endl;
        cout << "7. Sort Students by GPA" << endl;
        cout << "8. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addstudent();
            break;

        case 2:
            removestudent();
            break;

        case 3:
            search_student();
            break;

        case 4:
            display_all();
            break;

        case 5:
            enrollcourse();
            break;

        case 6:
            studentcourses();
            break;

        case 7:
            sortstudents();
            break;

        case 8:
            cout << "GOOD BYE!\n";
            break;

        default:
            cout << "invalid choice\n";

        }
    } while (choice != 8);

    return 0;
}