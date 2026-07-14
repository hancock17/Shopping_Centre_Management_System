#include "Restaurant.h"

Restaurant::Restaurant() : Business(){
    noOfSeats = 0;
}

Restaurant::Restaurant(char* gName, int gSize, int gSeats) : Business(gName,gSize){
    noOfSeats = gSeats;
}

void Restaurant::setNoOfSeats(int sSeats){
    noOfSeats = sSeats;
}

int Restaurant::getNoOfSeats(){
    return noOfSeats;
}

bool Restaurant::checkSuitability(int requiredSeats){
    if (noOfSeats >= requiredSeats)
        return true;
    else
        return false;
}

void Restaurant::printBusiness(){
    Business::printBusiness();
    std::cout<<"Number of Seats: "<<getNoOfSeats()<<std::endl;
}

void Restaurant::printBusinessEmployees(){
    Business::printBusinessEmployees();
    std::cout<<"Number of Seats: "<<getNoOfSeats()<<std::endl;
}

int Restaurant::getType(){
    return 0;
}
