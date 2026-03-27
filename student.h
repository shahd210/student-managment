#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <set>
#include "person.h"
using namespace std;
#pragma once

class student : public person
{
protected:
	int age;
	double GPA;
	int id;
	set<string>courses;

public:
	student();
	student(string n, int g, double gpa, int iid);

	int get_id();
	double get_gpa();

	void set_id(int iid);
	void set_gpa(int gppa);

	void display() override;

	void enroll_course(string course_name);

	void getall_courses();
};

#endif