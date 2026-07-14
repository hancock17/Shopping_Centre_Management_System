#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>
#include <cstring>

class Employee{
private:
    char *firstname;
    char *lastname;
    int SSN;

public:
    Employee(); // default constructor
    Employee(char*,char*); // constructor
    Employee(Employee& e); // copy constructor
    Employee& operator=(Employee& e); // assignment operator
    ~Employee(); // deconstructor

    //setter and getter functions
    void setEmployeeFirstName(char* setFirstName);
    char *getEmployeeFirstName();
    void setEmployeeLastName(char* setLastName);
    char *getEmployeeLastName();
    void setEmployeeSSN(int setSSN);
    int getEmployeeSSN();

    //methods
    void printEmployee();
    bool checkName(char* keyword);
};


#endif // EMPLOYEE_H_INCLUDED
