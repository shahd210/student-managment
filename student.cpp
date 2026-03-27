#include "student.h"
#include <iostream>
using namespace std;
student::student() :person() {
    GPA = 0;
    id = 0;
    age = 0;
};
student::student(string n, int g, double gpa, int iid) : person(n) {
    age = g;
    GPA = gpa;
    id = iid;

};

int student::get_id() {
    return id;
};
double student::get_gpa() {
    return GPA;
};

void student::set_id(int iid) {
    id = iid;
};
void student::set_gpa(int gppa) {
    GPA = gppa;
};

void student::display() {
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "GPA: " << GPA << "\n";
    cout << "ID: " << id << "\n";
};

void student::enroll_course(string course_name) {
    if (courses.count(course_name) > 0) {
        cout << "this course already enrolled\n";
    }
    else {
        courses.insert(course_name);
        cout << course_name << " enrolled successfully\n";
    }
};

void student::getall_courses() {
    if (courses.empty()) {
        cout << "no courses enrolled\n";
    }
    for (auto c : courses) {
        cout << c << "\n";
    }
};
