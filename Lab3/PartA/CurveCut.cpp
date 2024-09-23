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

CurveCut::CurveCut(int x, int y, double radius, double side_a, double side_b, string shapeName) : Circle(x, y, radius, shapeName), Rectangle(x, y, side_a, side_b, shapeName) {
                                                                                                  };

CurveCut::CurveCut(const CurveCut &source) : Circle(source), Rectangle(source) {
                                             };

CurveCut &CurveCut::operator=(const CurveCut &rhs)
{
    if (this != &rhs)
    {
        Circle::operator=(rhs);
        Rectangle::operator=(rhs);
    }
    return *this;
}

double CurveCut::area() const
{
    return (Circle::area() / 4) - Rectangle::area(); // Area of a quarter circle minus the area of a rectangle as the cut is in the top left corner
}

double CurveCut::perimeter() const
{
    return (Circle::perimeter() / 4) + (2 * Rectangle::perimeter()); // Perimeter of a quarter circle plus the perimeter of a rectangle as the cut is in the top left corner
}

void CurveCut::display() const
{
    cout << "CurveCut Name: " << Shape::shapeName << endl;
    Shape::origin.display();
    cout << "Radius: " << Circle::getRadius() << endl;
    cout << "Side A: " << getSideA() << endl;
    cout << "Side B: " << getSideB() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}