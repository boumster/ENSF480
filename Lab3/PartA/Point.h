/*
* File Name: Point.h
* Assignment: Lab 3 Exercise A
* Completed by: Jaden Haug-Uhrin and Phoenix Bouma
* Submission Date: Sept 27, 2024
*/
#ifndef Point_H
#define Point_H
#include <iostream>
using namespace std;

class Point
{
public:
    Point();
    Point(double x, double y);
    Point(const Point &source);
    Point &operator=(const Point &rhs);
    ~Point();
    double x() const;
    double y() const;
    void setx(double x);
    void sety(double y);
    void display() const;
    double distance(const Point &p) const;
    static double distance (const Point &a, const Point &b);
    static int count();
    int id() const;

private:
    double xM;
    double yM;
    static int counter;
    int idM;
};

#endif