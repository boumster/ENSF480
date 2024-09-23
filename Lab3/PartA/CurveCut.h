/*
 * File Name: CurveCut.h
 * Assignment: Lab 3 Exercise A
 * Completed by: Jaden Haug-Uhrin and Phoenix Bouma
 * Submission Date: Sept 27, 2024
 */

#ifndef CURVECUT_H
#define CURVECUT_H

#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

class CurveCut : public Circle, public Rectangle
{
public:
    CurveCut(double x, double y, double radius, double side_a, double side_b, string shapeName);
    virtual double area() const;
    virtual double perimeter() const;
    virtual void display() const;
    string getName() const;
    double distance(Shape &other) const;
};

#endif