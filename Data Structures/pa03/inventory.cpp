/**
 * @name Aditi Verma
 *       ASSIGNMENT 3 - Chapter 13
 * @date 3/20/24
 */

#include "inventory.h"
#include <iostream>
using namespace std;

//Default constructor
Inventory::Inventory(){}

/**
 * Gets dogLicense value
 * @return {string}  
 */
string Inventory::getDogLicense() 
{
    return dogLicense;
}

/**
 * Gets dogName value
 * @return {string}  
 */
string Inventory::getDogName() 
{
    return dogName;
}

/**
 * Gets ownerPhone value
 * @return {string}  
 */
string Inventory::getOwnerPhone() 
{
    return ownerPhone;
}

/**
 * Gets priceQuoted value
 * @return {float} 
 */
float Inventory::getPriceQuoted() 
{
    return priceQuoted;
}

/**
 * Sets dogLicense value if the string length is < 10
 * @param  {string} li : 
 */
void Inventory::setDogLicense(string li) 
{
    if(li.length() < 10) 
    {
        dogLicense = li;
    }
    else 
    {
        cout<<"\nLicense must be less than 10 characters.";
        exit(EXIT_FAILURE);
    }
}

/**
 * Sets dogName value if the string length is < 15
 * @param  {string} name
 */
void Inventory::setDogName(string name)
{
    if(name.length() < 15)
    {
        dogName = name;
    }
    else
    {
        cout<<"\nName must be less than 15 characters.";
        exit(EXIT_FAILURE);
    }
}

/**
 * Sets ownerPhone value if the string length is < 11
 * @param  {string} phone 
 */
void Inventory::setOwnerPhone(string phone)
{
    if(phone.length() < 11)
    {
        ownerPhone = phone;
    }
    else
    {
        cout<<"\nPhone number must be less than 11 characters.";
        exit(EXIT_FAILURE);
    }
}

/**
 * Sets priceQuoted value if the float is > 0
 * @param  {float} price 
 */
void Inventory::setPriceQuoted(float price)
{
    if(price >= 0)
    {
        priceQuoted = price;
    }
    else
    {
        cout<<"\nPrice must be greater than $0.00.";
        exit(EXIT_FAILURE);
    }
}