/*
* File Name: Circle.h
* Assignment: Lab 3 Exercise A
* Completed by: Jaden Haug-Uhrin and Phoenix Bouma
* Submission Date: Sept 27, 2024
*/
#ifndef Circle_H
#define Circle_H
#include <iostream>
using namespace std;

#include "Shape.h"

class Circle : public virtual Shape
{
public:
    Circle(int x, int y, double radius, string shapeName);
    Circle(const Circle &source);
    Circle &operator=(const Circle &rhs);
    virtual double area() const;
    virtual double perimeter() const;
    virtual void display() const;
    double getRadius() const;
    void setRadius(double radius);
private:
    double radius;
};

#endif