// company.cpp
#include <string>
#include <vector>
using namespace std;

struct Employee {
    string firstName;
    string lastName;
    string address;
    double salary;
};

struct EmployeeState {
    string state; // State of the employee
    Employee employee; // Linked to Employee
};

struct Customer {
    string firstName;
    string lastName;
    string address;
    string phoneNumber;
};

struct Company {
    string companyName;
    string companyAddress;

    vector <Employee> employees;
    vector <Customer> customers;
    vector <EmployeeState> employeeStates;

};