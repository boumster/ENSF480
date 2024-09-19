#ifndef Square_H
#define Square_H
#include <iostream>
using namespace std;

#include "Shape.h"

class Square : public Shape
{
public:
    Square(int x, int y, double side_a, string shapeName);
    Square(const Square &source);
    Square &operator=(const Square &rhs);
    virtual double area() const;
    virtual double perimeter() const;
    virtual void display() const;
    double getSide() const;
    void set_side_a(double side_a);

protected:
    double side_a;
};

#endif