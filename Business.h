#ifndef BUSINESS_H_INCLUDED
#define BUSINESS_H_INCLUDED

#include "Employee.h"

class Business{
private:
    char* name;
    int sizeinmetersquare;
    Employee employee[20]; // assume 20 according to assignment
    int noOfEmployees;

public:
    Business(); // default constructor
    Business(char* gName, int gSize); // constructor
    Business(Business& b); // copy constructor
    Business& operator=(Business& b); // assigment operator
    ~Business(); // deconstructor

    //setter and getter functions
    void setBusinessName(char* setName);
    char* getBusinessName();
    void setBusinessSize(int setSize);
    int getBusinessSize();
    void setNoOfEmployees(int setNoOfEmployee);
    int getNoOfEmployees();

    //methods
    void addEmployee(Employee& e);
    virtual void printBusiness(); // it is also in restaurant and shop classes
    virtual void printBusinessEmployees(); // it is also in restaurant and shop classes
    void searchByName(char* keyword);
    virtual int getType(); // to pure virtual function
};

#endif // BUSINESS_H_INCLUDED
