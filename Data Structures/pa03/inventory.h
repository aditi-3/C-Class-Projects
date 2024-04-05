/**
 * @name Aditi Verma
 *       ASSIGNMENT 3 - Chapter 13
 * @date 3/20/24
 */

#include <iostream>
#ifndef INVENTORY_H
#define INTENTORY_H
using namespace std;

class Inventory 
{
    private:
        string dogLicense; 
        string dogName; 
        string ownerPhone; 
        float priceQuoted;

    public:
        //getters
        string getDogLicense();
        string getDogName();
        string getOwnerPhone();
        float getPriceQuoted();

        //setters
        void setDogLicense(string li);
        void setDogName(string name);
        void setOwnerPhone(string phone);
        void setPriceQuoted(float price);
}; 
#endif