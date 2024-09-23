/*
* File Name: Shape.h
* Assignment: Lab 3 Exercise A
* Completed by: Jaden Haug-Uhrin and Phoenix Bouma
* Submission Date: Sept 27, 2024
*/
#ifndef Shape_H
#define Shape_H
#include <iostream>
using namespace std;

#include "Point.h"

class Shape
{
public:
    Shape(int x, int y, string shapeName);
    Shape(const Shape &source);
    Shape &operator=(const Shape &rhs);
    ~Shape();
    const Point &getOrigin() const;
    const string getShapeName() const;
    virtual void display() const;
    double distance(Shape &other) const;
    static double distance(Shape &theShape, Shape &other);
    void move(double dx, double dy);

protected:
    Point origin;
    char *shapeName;
};

#endif