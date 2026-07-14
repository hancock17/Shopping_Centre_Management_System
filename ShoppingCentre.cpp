#include "ShoppingCentre.h"
#include "Restaurant.h"
#include "Shop.h"

ShoppingCentre::ShoppingCentre(): businesses{} { // needed to initialize businesses
    name = new char[strlen("Undefined") + 1];
    strcpy(name, "Undefined");
    numberofBusinesses = 0;
}

ShoppingCentre::ShoppingCentre(char *gName): businesses{} { // needed to initialize businesses
    name = new char[strlen(gName) + 1];
    strcpy(name, gName);
    numberofBusinesses = 0;
}

ShoppingCentre::ShoppingCentre(ShoppingCentre& sc): businesses{} {
    name = new char[strlen(sc.name) + 1];
    strcpy(name, sc.name);
    numberofBusinesses = sc.numberofBusinesses;
}

ShoppingCentre &ShoppingCentre::operator=(ShoppingCentre& sc) {
    if (this !=&sc) {
        delete [] name;
        name = new char[strlen(sc.name) + 1];
        strcpy(name, sc.name);
        numberofBusinesses = sc.numberofBusinesses;
    }
    return *this;
}


ShoppingCentre::~ShoppingCentre(){
    delete[] name;
    for (int i=0; i < numberofBusinesses; i++) {
        delete businesses[i];
    }
}

void ShoppingCentre::setShoppingCentreName(char *setName){
    name = new char[strlen(setName)+1];
    strcpy(name,setName);
}

char* ShoppingCentre::getShoppingCentreName(){
    return name;
}

void ShoppingCentre::setNoOfBusinesses(int noOfBusinesses){
    numberofBusinesses = noOfBusinesses;
}

int ShoppingCentre::getNoOfBusinesses(){
    return numberofBusinesses;
}

Business* ShoppingCentre::getBusinessAt(int index) {
    if (index >= 0 && index < numberofBusinesses)
        return businesses[index];
    return nullptr;
}


void ShoppingCentre::addBusiness(Business* business){
    if(numberofBusinesses < 50) {
        businesses[numberofBusinesses++] = business;
        std::cout<<"Business -"<<business->getBusinessName()<<"- added"<<std::endl;
    }
    else
        std::cout<<"Max Limit to add business"<<std::endl;
}

void ShoppingCentre::printBusinesses(){
    for(int i=0; i<numberofBusinesses; i++)
        businesses[i]->printBusiness();
}

void ShoppingCentre::printBusinessesEmployees(){
    for(int i=0; i<numberofBusinesses; i++)
        businesses[i]->printBusinessEmployees();
}

void ShoppingCentre::printShopStatistics(){
    int clothing = 0, technology = 0, accessories = 0, beauty = 0;
    for (int i = 0; i < numberofBusinesses; ++i) {
        if (businesses[i]->getType() == 1)
            clothing++;
        else if (businesses[i]->getType() == 2)
            technology++;
        else if (businesses[i]->getType() == 3)
            accessories++;
        else if (businesses[i]->getType() == 4)
            beauty++;
    }
    std::cout << "Clothing shops: " << clothing << "\n";
    std::cout << "Technology shops: " << technology << "\n";
    std::cout << "Accessories shops: " << accessories << "\n";
    std::cout << "Beauty shops: " << beauty << "\n";
}

void ShoppingCentre::printShopsByType(int type){
    for(int i = 0; i < numberofBusinesses; i++){
        if(businesses[i]->getType() == type)
            businesses[i]->printBusiness();
    }
}

void ShoppingCentre::printSuitableRestaurants(int requiredNumberSeats) {
    for (int i = 0; i < numberofBusinesses; i++) {
        if (businesses[i]->getType() == 0) { // Restaurant type
            Restaurant* r = (Restaurant*) businesses[i];
        if (r->checkSuitability(requiredNumberSeats)) {
            r->printBusiness();
        }
        }
    }
}

void ShoppingCentre::searchByEmployeeName(char *keyword) {
    for (int i = 0; i < numberofBusinesses; i++) {
        businesses[i]->searchByName(keyword);
    }
}

void ShoppingCentre::printLargestBusiness() {
    if (numberofBusinesses == 0) return;
    int maxIndex = 0;
    for (int i = 1; i < numberofBusinesses; i++) {
        if (businesses[i]->getBusinessSize() > businesses[maxIndex]->getBusinessSize()) {
            maxIndex = i;
        }
    }
    businesses[maxIndex]->printBusiness();
}




