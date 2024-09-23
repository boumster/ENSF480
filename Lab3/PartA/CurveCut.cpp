/*
 * File Name: CurveCut.cpp
 * Assignment: Lab 3 Exercise A
 * Completed by: Jaden Haug-Uhrin and Phoenix Bouma
 * Submission Date: Sept 27, 2024
 */

#include <iostream>
#include "CurveCut.h"
#include <math.h>

using namespace std;

CurveCut::CurveCut(int x, int y, double side_a, double side_b, double radius, string shapeName)
    : Shape(x, y, shapeName), Circle(x, y, radius, shapeName), Rectangle(x, y, side_a, side_b, shapeName)
{
    if (radius > side_a || radius > side_b)
    {
        cout << "Error: The radius of the cut cannot be larger than the sides of the rectangle." << endl;
        exit(1);
    }
}

CurveCut::CurveCut(const CurveCut &source) : Shape(source), Circle(source), Rectangle(source) {
                                             };

CurveCut &CurveCut::operator=(const CurveCut &rhs)
{
    if (this != &rhs)
    {
        Shape::operator=(rhs);
        Circle::operator=(rhs);
        Rectangle::operator=(rhs);
    }
    return *this;
}

double CurveCut::area() const
{
    return Rectangle::area() - (Circle::area() / 4); // Area of a quarter circle minus the area of a rectangle as the cut is in the top left corner
}

double CurveCut::perimeter() const
{
    double circlePerimeter = Circle::perimeter() / 4; // Quarter of the circle's perimeter within the cut
    double rectanglePerimeter = Rectangle::perimeter();
    double result = circlePerimeter + rectanglePerimeter - (2 * Circle::getRadius()); // Subtracting the length of the cut from the perimeter
    return result;
}

void CurveCut::display() const
{
    cout << "CurveCut Name: " << Shape::shapeName << endl;
    Shape::origin.display();
    cout << "Width: " << getSideA() << endl;
    cout << "Length: " << getSideB() << endl;
    cout << "Radius of the cut: " << Circle::getRadius() << endl;
}

string CurveCut::getName() const
{
    return Shape::shapeName;
}

double CurveCut::distance(Shape &other) const
{
    return Shape::distance(other);
}