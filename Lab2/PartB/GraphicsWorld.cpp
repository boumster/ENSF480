/*
* File Name: GraphicsWorld.cpp
* Assignment: Lab 2 Exercise B
* Completed by: Jaden Haug-Uhrin and Phoenix Bouma
* Submission Date: Sept 20, 2024
*/
#include "GraphicsWorld.h"
#include "Rectangle.h"
#include "Square.h"
#include "Shape.h"
#include "Point.h"

void GraphicsWorld::run()
{
#if 1 // Change 0 to 1 to test Point
    Point m(6, 8);
    Point n(6, 8);
    n.setx(9);
    cout << "\nExpected to dispaly the distance between m and n is: 3";
    cout << "\nThe distance between m and n is: " << m.distance(n);
    cout << "\nExpected second version of the distance function also print: 3";
    cout << "\nThe distance between m and n is again: "
         << Point::distance(m, n);
#endif // end of block to test Point
#if 1  // Change 0 to 1 to test Square
    cout << "\n\nTesting Functions in class Square:" << endl;
    Square s(5, 7, 12, "SQUARE - S");
    s.display();
#endif // end of block to test Square
#if 1  // Change 0 to 1 to test Rectangle
    cout << "\nTesting Functions in class Rectangle:";
    Rectangle a(5, 7, 12, 15, "RECTANGLE A");
    a.display();
    Rectangle b(16, 7, 8, 9, "RECTANGLE B");
    b.display();
    double d = a.distance(b);
    cout << "\nDistance between square a, and b is: " << d << endl;
    Rectangle rec1 = a;
    rec1.display();
    cout << "\nTesting assignment operator in class Rectangle:" << endl;
    Rectangle rec2(3, 4, 11, 7, "RECTANGLE rec2");
    rec2.display();
    rec2 = a;
    a.set_side_b(200);
    a.set_side_a(100);
    cout << "\nExpected to display the following values for objec rec2: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n"
         << "X-coordinate: 5\n"
         << "Y-coordinate: 7\n"
         << "Side a: 12\n"
         << "Side b: 15\n"
         << "Area: 180\n"
         << "Perimeter: 54\n";
    cout << "\nIf it doesn't there is a problem with your assignment operator.\n"
         << endl;
    rec2.display();
    cout << "\nTesting copy constructor in class Rectangle:" << endl;
    Rectangle rec3(a);
    rec3.display();
    a.set_side_b(300);
    a.set_side_a(400);
    cout << "\nExpected to display the following values for objec rec2: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n"
         << "X-coordinate: 5\n"
         << "Y-coordinate: 7\n"
         << "Side a: 100\n"
         << "Side b: 200\n"
         << "Area: 20000\n"
         << "Perimeter: 600\n";
    cout << "\nIf it doesn't there is a problem with your assignment operator.\n"
         << endl;
    rec3.display();
#endif // end of block to test Rectangle
#if 1  // Change 0 to 1 to test using array of pointer and polymorphism
    cout << "\nTesting array of pointers and polymorphism:" << endl;
    Shape *sh[4];
    sh[0] = &s;
    sh[1] = &b;
    sh[2] = &rec1;
    sh[3] = &rec3;
    sh[0]->display();
    sh[1]->display();
    sh[2]->display();
    sh[3]->display();
#endif // end of block to test array of pointer and polymorphis
}

int main()
{
    GraphicsWorld gw;
    gw.run();
    return 0;
}