#include "Point.h"
#include <iostream>
#include <math.h>

using namespace std;

Point::Point()
{
    xM = 0;
    yM = 0;
    counter++;
    idM = 1000 + counter;
}

Point::Point(double x, double y)
{
    xM = x;
    yM = y;
    counter++;
    idM = 1000 + counter;
}

Point::Point(const Point &source)
{
    xM = source.xM;
    yM = source.yM;
    counter++;
    idM = 1000 + counter;
}

Point &Point::operator=(const Point &rhs)
{
    if (this != &rhs)
    {
        xM = rhs.xM;
        yM = rhs.yM;
    }
    return *this;
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