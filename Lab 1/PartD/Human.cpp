#include "Human.h"
#include <cstring>
#include <iostream>
using namespace std;

// Constructor
Human::Human(const char* nam, double x, double y)
    : location(x, y), name(new char[strlen(nam) + 1]) {
    strcpy(name, nam);
}

// Copy constructor
Human::Human(const Human& other)
    : location(other.location), name(new char[strlen(other.name) + 1]) {
    strcpy(name, other.name);
}

// Destructor
Human::~Human() {
    delete[] name;
}

// Assignment operator
Human& Human::operator=(const Human& other) {
    if (this != &other) {
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        location = other.location;
    }
    return *this;
}

// Accessor for name
const char* Human::get_name() const {
    return name;
}

// Mutator for name
void Human::set_name(const char* new_name) {
    delete[] name;
    name = new char[strlen(new_name) + 1];
    strcpy(name, new_name);
}

// Accessor for location
Point Human::get_point() const {
    return location;
}

// Display function
void Human::display() const {
    cout << "Human Name: " << name << "\nHuman Location: "
         << location.get_x() << " ,"
         << location.get_y() << ".\n" << endl;
}
