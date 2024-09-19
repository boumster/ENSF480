#include "Shape.h"
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

Shape::Shape(int x, int y, string shapeName)
{
    this->origin = Point(x, y);
    this->shapeName = new char[shapeName.length() + 1];
    strcpy(this->shapeName, shapeName.c_str());
}

Shape::Shape(const Shape &source)
{
    origin = source.origin;
    shapeName = new char[strlen(source.shapeName) + 1];
    strcpy(shapeName, source.shapeName);
}

Shape &Shape::operator=(const Shape &rhs)
{
    if (this != &rhs)
    {
        origin = rhs.origin;
        delete[] shapeName;
        shapeName = new char[strlen(rhs.shapeName) + 1];
        strcpy(shapeName, rhs.shapeName);
    }
    return *this;
}

Shape::~Shape()
{
    delete[] shapeName;
}

const Point &Shape::getOrigin() const
{
    return origin;
}

const string Shape::getShapeName() const
{
    return shapeName;
}

void Shape::display() const
{
    cout << "Shape Name: " << shapeName << endl;
    origin.display();
}

double Shape::distance(Shape &other) const
{
    return origin.distance(other.origin);
}

double Shape::distance(Shape &theShape, Shape &other)
{
    return theShape.origin.distance(other.origin);
}

void Shape::move(double dx, double dy)
{
    origin.setx(origin.x() + dx);
    origin.sety(origin.y() + dy);
}
