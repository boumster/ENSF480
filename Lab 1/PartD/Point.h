#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x; // x coordinate of a location on Cartesian Plane
    double y; // y coordinate of a location on Cartesian Plane

public:
    // Constructor with default values
    Point(double a = 0, double b = 0);

    // Accessors
    double get_x() const;
    double get_y() const;

    // Mutators
    void set_x(double a);
    void set_y(double a);
};

#endif
