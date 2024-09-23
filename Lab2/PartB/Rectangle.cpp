/*
* File Name: Rectangle.cpp
* Assignment: Lab 2 Exercise B
* Completed by: Jaden Haug-Uhrin and Phoenix Bouma
* Submission Date: Sept 20, 2024
*/
#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(int x, int y, double side_a, double side_b, string shapeName) : Square(x, y, side_a, shapeName)
{
    this->side_b = side_b;
}

double Rectangle::area() const
{
    return side_a * side_b;
}

double Rectangle::perimeter() const
{
    return 2 * (side_a + side_b);
}

void Rectangle::display() const
{
    cout << "Rectangle Name: " << shapeName << endl;
    origin.display();
    cout << "Side A: " << side_a << endl;
    cout << "Side B: " << side_b << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}

double Rectangle::getSideB() const
{
    return side_b;
}

void Rectangle::set_side_b(double side_b)
{
    this->side_b = side_b;
}