#ifndef SHOP_H_INCLUDED
#define SHOP_H_INCLUDED

#include "Business.h"

enum shopType{None = -1, Clothing = 1, Technology = 2, Accessories = 3, Beauty = 4};

class Shop : public Business{
private:
    shopType type;
public:
    Shop(); // default constructor
    Shop(char* gName, int gSize, shopType newType); // parameter constructor

    //setter and getter functions
    void setShopType(shopType newType);
    shopType getShopType();

    //methods
    void printBusiness() override; // not to conflict with the method in business class (warning)
    void printBusinessEmployees() override; // not to conflict with the method in business class (warning)
    int getType() override;
};


#endif // SHOP_H_INCLUDED
