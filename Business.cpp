#include "Business.h"

Business::Business() {
    name = new char[strlen("Undefined") + 1];
    sizeinmetersquare = -1;
    noOfEmployees = 0;
}

Business::Business(char* gName, int gSize) { // needed to initialize employee
    name = new char[strlen(gName) + 1];
    strcpy(name, gName);
    sizeinmetersquare = gSize;
    noOfEmployees = 0;
}

Business::Business(Business& b) {
    name = new char[strlen(b.name) + 1];
    strcpy(name, b.name);
    sizeinmetersquare = b.sizeinmetersquare;
    noOfEmployees = b.noOfEmployees;
}

Business &Business::operator=(Business& b) {
    if (this != &b) {
        delete[] name;
        name = new char[strlen(b.name) + 1];
        strcpy(name, b.name);
        sizeinmetersquare = b.sizeinmetersquare;
        noOfEmployees = b.noOfEmployees;
    }
    return *this;
}

Business::~Business(){
    delete[] name;
}

void Business::setBusinessName(char* setName){
    delete[] name;
    name = new char[strlen(setName)+1];
    strcpy(name,setName);
}

char* Business::getBusinessName(){
    return name;
}

void Business::setBusinessSize(int setSize){
    sizeinmetersquare = setSize;
}

int Business::getBusinessSize(){
    return sizeinmetersquare;
}

void Business::setNoOfEmployees(int setNoOfEmployee){
    noOfEmployees = setNoOfEmployee;
}

int Business::getNoOfEmployees(){
    return noOfEmployees;
}

void Business::addEmployee(Employee& e){
    if(noOfEmployees < 20){
        employee[noOfEmployees] = e;
        noOfEmployees++;
    }
}

void Business::printBusiness(){
    std::cout<<"Business name: "<<name<<" Business size (m^2): "<<sizeinmetersquare<<" Number of Employess: "<<noOfEmployees<<std::endl;
}

void Business::printBusinessEmployees(){
    std::cout<<"Business name: "<<name<<" Business size (m^2): "<<sizeinmetersquare<<std::endl;
    std::cout<<"Employees' ";
    for(int i=0; i<noOfEmployees; i++){
        employee[i].printEmployee();
    }
}

void Business::searchByName(char* keyword){
    for(int i=0; i<noOfEmployees; i++){
        if(employee[i].checkName(keyword)){
            std::cout<<"Name searched -> "<<std::endl;
            std::cout<<"Workplace: "<<name<<" -- "<<"Employee's ";
            employee[i].printEmployee();
        }
    }
}

int Business::getType() {
    return 0;
}
