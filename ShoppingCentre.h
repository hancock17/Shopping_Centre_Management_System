#ifndef SHOPPINGCENTRE_H_INCLUDED
#define SHOPPINGCENTRE_H_INCLUDED

#include <iostream>
#include <cstring>
#include "Business.h"

class ShoppingCentre{
private:
    char* name;
    Business* businesses[50];
    int numberofBusinesses;
public:
    ShoppingCentre(); // default constructor
    ShoppingCentre(char*); // constructor
    ShoppingCentre(ShoppingCentre&); // copy constructor
    ShoppingCentre& operator=(ShoppingCentre&); // assignment operator
    ~ShoppingCentre(); // deconstructor

    //setter and getter functions
    void setShoppingCentreName(char* setName);
    char* getShoppingCentreName();
    void setNoOfBusinesses(int noOfBusinesses);
    int getNoOfBusinesses();
    Business* getBusinessAt(int index); // helper getter function to add employee for the business

    //methods
    void addBusiness(Business* business);
    void printBusinesses();
    void printBusinessesEmployees();
    void printShopStatistics();
    void printShopsByType(int type);
    void printSuitableRestaurants(int requiredNumberSeats);
    void searchByEmployeeName(char* keyword);
    void printLargestBusiness();
};

#endif // SHOPPINGCENTRE_H_INCLUDED
