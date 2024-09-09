#ifndef HUMAN_H
#define HUMAN_H

#include "Point.h"

class Human {
protected:
    Point location; // Location of an object of Human on a Cartesian Plane
    char *name;     // Human's name

public:
    // Constructor
    Human(const char* nam = "", double x = 0, double y = 0);

    // Copy constructor
    Human(const Human& other);

    // Destructor
    ~Human();

    // Assignment operator
    Human& operator=(const Human& other);

    // Accessor for name
    const char* get_name() const;

    // Mutator for name
    void set_name(const char* name);

    // Accessor for location
    Point get_point() const;

    // Display function
    void display() const;
};

#endif
