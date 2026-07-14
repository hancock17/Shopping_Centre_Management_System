#ifndef RESTAURANT_H_INCLUDED
#define RESTAURANT_H_INCLUDED

#include "Business.h"

//restaurant is the subclass of the class of the business
class Restaurant : public Business{
private:
    int noOfSeats;
public:
    Restaurant(); // default constructor
    Restaurant(char* gName, int gSize, int gSeats); // constructor

    // setter and getter functions
    void setNoOfSeats(int sSeats);
    int getNoOfSeats();

    //methods
    bool checkSuitability(int requiredSeats);
    void printBusiness() override; // not to conflict with the method in business class (warning)
    void printBusinessEmployees() override; // not to conflict with the method in business class (warning)
    int getType() override;
};

#endif // RESTAURANT_H_INCLUDED
