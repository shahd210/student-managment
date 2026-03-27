#include "person.h"

person::person()
{
    name = "";
}
person::person(string n) {
    name = n;
};

void  person::set_name(string namee) {
    name = namee;
};
string  person::get_name() {
    return name;
};

