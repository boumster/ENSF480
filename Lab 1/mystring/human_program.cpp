#include <cstring>
#include <iostream>
using namespace std;
class Point{
private:
    double x;     // x coordinate of a location on Cartisian Plain
    double y;     // y coordinate of a location on Cartisian Plain
public:
    Point(double a =0, double b =0): x(a), y(b) {}
    double get_x(){return x;}
    double get_y(){return y;}
    void set_x(double a) { x = a;};
    void set_y(double a) { y = a;};
};

class Human {
protected:
    Point location;   // Location of an object of Human on a Cartisian Plain
    char *name;       // Human's name
public:
    
    Human(const char* nam="", double x=0, double y=0): name(new char[strlen(nam)+1]) {
        strcpy(this ->name, nam);
        location.set_x(x);
        location.set_y(y);
    }
    
    char* get_name() {return name;} 
            
    void set_name(char* name) {                  
        this->name = new char[strlen(name)+1];        
        strcpy(this ->name, name);
    }
   
    Point get_point()const {return location;}
    
    void display() {                      
        cout << "Human Name: " << name << "\nHuman Location: "
        << location.get_x() << " ,"
        << location.get_y() << ".\n" << endl;
    }
};



#include <iostream>

int main(int argc, char **argv)
{
	double x = 2000, y = 3000;
	Human h("Ken Lai", x , y); 
    h.display();
	return 0;
}

