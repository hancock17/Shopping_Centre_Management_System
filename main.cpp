// Kaan Kırgıl 2526515
//I read and accept the submission rules and the extra rules specified
//in each question. This is my own work that is done by myself only */

#include "ShoppingCentre.h" // includes also business and employee
#include "Restaurant.h"
#include "Shop.h"

int main() {

    std::cout << "Kalkanli Shopping Centre" << std::endl;
    ShoppingCentre sc((char*)"Kalkanli Shopping Centre");
    int option = 0;
    while (option != 10) {
        std::cout<<"1. Add a new business to the shopping centre\n";
        std::cout<<"2. Add an employee to a business\n";
        std::cout<<"3. Print all the businesses in the shopping centre with the number of employees in each business\n";
        std::cout<<"4. Print all the businesses in the shopping centre with the details of employees in each business\n";
        std::cout<<"5. Print the count of each type of shop in the shopping centre\n";
        std::cout<<"6. Print the details of the shops whose type is a given type (1: Clothing, 2: Technology, 3: Accessories, 4: Beauty)\n";
        std::cout<<"7. Print the suitable restaurants based on a given required number of seats\n";
        std::cout<<"8. Search for employees by name\n";
        std::cout<<"9. Print the largest business in terms of size in the shopping centre\n";
        std::cout<<"10. Exit\n";
        std::cout<<"Enter your choice: ";
        std::cin>>option;

        switch (option) {
            case 1: {
                int type;
                char name[100];
                int size;

                std::cout<<"Enter business type (0: Restaurant, 1: Clothing, 2: Technology, 3: Accessories, 4: Beauty): ";
                std::cin>>type;
                std::cout<<"Enter business name: ";
                std::cin>>name;
                std::cout<<"Enter business size (m^2): ";
                std::cin>>size;

                if (type == 0) {
                    int seats;
                    std::cout<<"Enter number of seats: ";
                    std::cin>>seats;
                    Restaurant* r = new Restaurant(name,size,seats);
                    sc.addBusiness(r);
                }
                else {
                    Shop* s = new Shop(name,size,(shopType) type);
                    sc.addBusiness(s);
                }
                break;
            }
            case 2: {
                char targetName[100];
                std::cout<<"Enter target business name: ";
                std::cin>>targetName;

                Business* target = nullptr;
                for (int i = 0; i < sc.getNoOfBusinesses(); i++) {
                    if (strcmp(sc.getBusinessAt(i)->getBusinessName(), targetName) == 0) {
                        target = sc.getBusinessAt(i); // matched if business exists
                        break;
                    }
                }

                if (target == nullptr) {
                    std::cout<<"Business not found.\n";
                } else {
                    char fname[100], lname[100];
                    int ssn;
                    std::cout<<"Enter employee first name: ";
                    std::cin>>fname;
                    std::cout<<"Enter employee last name: ";
                    std::cin>>lname;
                    std::cout<<"Enter SSN: ";
                    std::cin>>ssn;

                    Employee e(fname, lname);
                    e.setEmployeeSSN(ssn);
                    target->addEmployee(e);

                    std::cout << "Employee -" << fname << " " << lname << "- added\n";
                }
                break;
            }
            case 3: {
                sc.printBusinesses();
                break;
            }
            case 4: {
                sc.printBusinessesEmployees();
                break;
            }
            case 5: {
                sc.printShopStatistics();
                break;
            }
            case 6: {
                int type;
                std::cout<<"Enter shop type ((1: Clothing, 2: Technology, 3: Accessories, 4: Beauty): ";
                std::cin>>type;
                sc.printShopsByType(type);
                break;
            }
            case 7: {
                int seats;
                std::cout<<"Enter required number of seats: ";
                std::cin>>seats;
                sc.printSuitableRestaurants(seats);
                break;
            }
            case 8: {
                char name[100];
                std::cout<<"Enter employee name to search: ";
                std::cin>>name;
                sc.searchByEmployeeName(name);
                break;
            }
            case 9: {
                sc.printLargestBusiness();
                break;
            }
            case 10: {
                option = 10;
                std::cout<<"BYE!!!\n";
                break;
            }
            default:
                std::cout<<"Invalid option. Try again\n";
        }
    }
    return 0;
}