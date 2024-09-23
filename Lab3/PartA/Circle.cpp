/*
 * File Name: Circle.cpp
 * Assignment: Lab 3 Exercise A
 * Completed by: Jaden Haug-Uhrin and Phoenix Bouma
 * Submission Date: Sept 27, 2024
 */
#include "Circle.h"
#include <iostream>
#include <math.h>

using namespace std;

Circle::Circle(double x, double y, double radius, string shapeName) : Shape(Point(x,y), shapeName)
{
    this->radius = radius;
}

double Circle::area() const
{
    return M_PI * radius * radius;
}

double Circle::perimeter() const
{
    return 2 * M_PI * radius;
}

void Circle::display() const
{
    cout << "Circle Name: " << shapeName << endl;
    origin.display();
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
    cout << "Radius: " << radius << endl;
}

double Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(double radius)
{
    this->radius = radius;
}