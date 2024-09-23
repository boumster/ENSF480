/*
* File Name: Rectangle.h
* Assignment: Lab 2 Exercise B
* Completed by: Jaden Haug-Uhrin and Phoenix Bouma
* Submission Date: Sept 20, 2024
*/
#ifndef Rectangle_H
#define Rectangle_H
#include <iostream>
using namespace std;

#include "Square.h"

class Rectangle : public Square
{
public:
    Rectangle(int x, int y, double side_a, double side_b, string shapeName);
    double area() const;
    double perimeter() const;
    void display() const;
    double getSideB() const;
    void set_side_b(double side_b);

protected:
    double side_b;
};

#endif