/**
 * @name Aditi Verma
 *       ASSIGNMENT 3 - Chapter 13
 * @date 3/13/24
 */

#ifndef INVENTORY_H
#define INTENTORY_H
#include <iostream>
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
        string getDogLicense() const;
        string getDogName() const;
        string getOwnerPhone() const;
        float getPriceQuoted() const;

        //setters
        void setDogLicense(string);
        void setDogName(string);
        void setOwnerPhone(string);
        void setPriceQuoted(float);
}; 
#endif