/*
* File Name: Point.cpp
* Assignment: Lab 3 Exercise A
* Completed by: Jaden Haug-Uhrin and Phoenix Bouma
* Submission Date: Sept 27, 2024
*/
#include "Point.h"
#include <iostream>
#include <math.h>

using namespace std;

Point::Point(double x, double y)
{
    xM = x;
    yM = y;
    counter++;
    idM = 1000 + counter;
}

Point::~Point()
{
    counter--;
}

double Point::x() const
{
    return xM;
}

double Point::y() const
{
    return yM;
}

void Point::setx(double x)
{
    xM = x;
}

void Point::sety(double y)
{
    yM = y;
}

void Point::display() const
{
    cout << "X-coordinate:" << xM << endl
         << "Y-coordinate:" << yM << endl;
}

double Point::distance(const Point &p) const
{
    double xDiff = xM - p.xM;
    double yDiff = yM - p.yM;
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}

double Point::distance(const Point &a, const Point &b)
{
    double xDiff = a.xM - b.xM;
    double yDiff = a.yM - b.yM;
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}

int Point::count()
{
    return counter;
}

int Point::counter = 0;

int Point::id() const
{
    return idM;
}