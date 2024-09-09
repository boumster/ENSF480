#include "Point.h"

// Constructor with initialization list
Point::Point(double a, double b) : x(a), y(b) {}

// Accessors
double Point::get_x() const { return x; }
double Point::get_y() const { return y; }

// Mutators
void Point::set_x(double a) { x = a; }
void Point::set_y(double a) { y = a; }
