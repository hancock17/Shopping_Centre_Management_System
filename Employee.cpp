#include "Employee.h"

#include <chrono>

Employee::Employee() {
    firstname = new char[strlen("Undefined") + 1];
    strcpy(firstname, "Undefined");

    lastname = new char[strlen("Undefined") + 1];
    strcpy(lastname, "Undefined");

    SSN = -1;
}

Employee::Employee(char *first,char *last){

    firstname = new char[strlen(first)+1];
    strcpy(firstname,first);
    lastname = new char[strlen(last)+1];
    strcpy(lastname,last);
    SSN = -1;
}

Employee::Employee(Employee& e) {
    firstname = new char[strlen(e.firstname) + 1];
    strcpy(firstname,e.firstname);
    lastname = new char[strlen(e.lastname) + 1];
    strcpy(lastname,e.lastname);
    SSN = e.SSN;
}

Employee &Employee::operator=(Employee& e) {
    if (this != &e) {
        firstname = new char[strlen(e.firstname) + 1];
        strcpy(firstname,e.firstname);
        lastname = new char[strlen(e.lastname) + 1];
        strcpy(lastname,e.lastname);
        SSN = e.SSN;
    }
    return *this;
}

Employee::~Employee(){
    delete[] firstname;
    delete[] lastname;
}

void Employee::setEmployeeFirstName(char* setFirstName){
    delete[] firstname; // not to occur memory leak
    firstname = new char[strlen(setFirstName)+1];
    strcpy(firstname,setFirstName);
}

char* Employee::getEmployeeFirstName(){
    return firstname;
}

void Employee::setEmployeeLastName(char* setLastName){
    delete[] lastname;
    lastname = new char[strlen(setLastName)+1];
    strcpy(lastname,setLastName);
}

char* Employee::getEmployeeLastName(){
    return lastname;
}

void Employee::setEmployeeSSN(int setSSN){
    SSN = setSSN;
}

int Employee::getEmployeeSSN(){
    return SSN;
}

void Employee::printEmployee(){
    std::cout<<"name: "<<firstname<<" "<<lastname<<" SSN: "<<SSN<<std::endl;
}

bool Employee::checkName(char *keyword){
    if (strcmp(firstname, keyword) == 0 || strcmp(lastname, keyword) == 0)
        return true;
    else
        return false;
}
