/**
 * @name Aditi Verma
 *       ASSIGNMENT 3 - Chapter 13
 * @date 3/20/24
 */

#include <iostream>
#include <iomanip>
#include "inventory.h"
using namespace std;

int main()
{
    // Initialize array and determine it's number of rows and columns
    Inventory customers[5];
    int i = 0; //Keeps track of the number of customers inputted, max is 5
    int input = 0;

    // Excecute menu until user exits
    do{
        // User input for menu
        cout<<"\n\n----------MENU----------";
        cout<<"\n1). Enter a new job";
        cout<<"\n2). List all current jobs";
        cout<<"\n3). Exit";
        cout<<"\nEnter menu choice: ";
        cin>>input;
        
        //Catch input error
        if (input < 1 || input > 3)
        {
            cout<<"\nWrong input, try again!";
        }
        
        // Switch statements for each menu selection
        float sum = 0; //Total number of quotes
        switch(input)
        {
            case 1:
                if(i < 5)
                {
                    string data; //Stores input values for all strings
                    float bath; //Stores input values for quota
                    //Validates user input for each object attribute inputs
                    cout<<"\nEnter dog license: ";
                    cin>>data;
                    while(data.length() > 10)
                    {
                        cout<<"\nEnter dog license: ";
                        cin>>data;
                    }
                    customers[i].setDogLicense(data);

                    cout<<"\nEnter dog Name: ";
                    cin>>data;
                    while(data.length() > 15)
                    {
                        cout<<"\nEnter dog Name: ";
                        cin>>data;
                    }
                    customers[i].setDogName(data);

                    cout<<"\nEnter phone number: ";
                    cin>>data;
                    while(data.length() > 11)
                    {
                        cout<<"\nEnter phone number: ";
                        cin>>data;
                    }
                    customers[i].setOwnerPhone(data);

                    cout<<"\nEnter price for bath: ";
                    cin>>bath;
                    while(bath < 0)
                    {
                        cout<<"\nEnter price for bath: ";
                        cin>>bath;
                    }
                    customers[i].setPriceQuoted(bath); 
                    i++;
                }
                break;
            case 2:
                //Print out all customers and total quota
                cout<<"\nCurrent Jobs:";
                cout<<"\n"<<"License"<<"\t"<<"Name"<<"\t"<<"Phone number"<<"\t"<<"Price";
                for(int i = 0; i < 5; i++)
                {
                    if(customers[i].getDogLicense() != "")
                    {
                        sum += customers[i].getPriceQuoted();
                        cout<<"\n"<<customers[i].getDogLicense()<<"\t"<<customers[i].getDogName();
                        cout<<"\t"<<customers[i].getOwnerPhone()<<"\t"<<"\t"<<setprecision(2)<<fixed<<customers[i].getPriceQuoted();
                    }
                }
                cout<<"\n\nYou currently have a total of $"<<setprecision(2)<<fixed<<sum<<endl;
                break;
            case 3:
                cout<<"Thank you!";
                break;
        }
    }
    while (input != 3); 
}