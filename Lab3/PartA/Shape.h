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
    Shape(const Point &p, const string shapeName);
    Shape(const Shape &source);
    Shape &operator=(const Shape &rhs);
    ~Shape();
    const Point &getOrigin() const;
    const string getName() const;
    virtual void display() const;
    double distance(Shape &other) const;
    static double distance(Shape &theShape, Shape &other);
    void move(double dx, double dy);
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

protected:
    Point origin;
    char *shapeName;
};

#endif