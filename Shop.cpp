#include "Shop.h"

Shop::Shop() : Business(){
    type = None;
}

Shop::Shop(char* gName, int gSize, shopType newType) : Business(gName,gSize){
    type = newType;
}

void Shop::setShopType(shopType newType){
    type = newType;
}

shopType Shop::getShopType(){
    return type;
}

void Shop::printBusiness(){
    Business::printBusiness();
    std::cout << "Shop Type: ";
    switch (type) {
        case Clothing:
            std::cout << "Clothing"; break;
        case Technology:
            std::cout << "Technology"; break;
        case Accessories:
            std::cout << "Accessories"; break;
        case Beauty:
            std::cout << "Beauty"; break;
        default:
            std::cout << "None"; break;
    }
    std::cout << std::endl;
}

void Shop::printBusinessEmployees(){
    Business::printBusinessEmployees();
    std::cout << "Shop Type: ";
    switch (type) {
        case Clothing:
            std::cout << "Clothing"; break;
        case Technology:
            std::cout << "Technology"; break;
        case Accessories:
            std::cout << "Accessories"; break;
        case Beauty:
            std::cout << "Beauty"; break;
        default:
            std::cout << "None"; break;
    }
    std::cout << std::endl;
}

int Shop::getType(){
    if (type == Clothing) return 1;
    else if (type == Technology) return 2;
    else if (type == Accessories) return 3;
    else if (type == Beauty) return 4;
    else return -1;
}
