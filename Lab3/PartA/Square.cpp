/*
* File Name: Square.cpp
* Assignment: Lab 3 Exercise A
* Completed by: Jaden Haug-Uhrin and Phoenix Bouma
* Submission Date: Sept 27, 2024
*/
#include <iostream>
using namespace std;

#include "Square.h"

Square::Square(int x, int y, double side_a, string shapeName) : Shape(x, y, shapeName)
{
    this->side_a = side_a;
}

Square::Square(const Square &source) : Shape(source)
{
    side_a = source.side_a;
}

Square &Square::operator=(const Square &rhs)
{
    if (this != &rhs)
    {
        Shape::operator=(rhs);
        side_a = rhs.side_a;
    }
    return *this;
}

double Square::area() const
{
    return double(side_a * side_a);
}

double Square::perimeter() const
{
    return double(4 * side_a);
}

void Square::display() const
{
    cout << "Square Name: " << shapeName << endl;
    origin.display();
    cout << "Side: " << side_a << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}

double Square::getSide() const
{
    return side_a;
}

void Square::set_side_a(double side_a)
{
    this->side_a = side_a;
}