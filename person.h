#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
#pragma once

class person
{
protected:
    string name;
public:
    person();

    person(string n);

    void set_name(string namee);
    string get_name();

    virtual  void  display() = 0;


};

#endif