//Menu-driven porgram converting metric english conversions

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int choice1;
    int choice2;
    //Outer menu
    do 
    {
        cout<<"\nMain menu: \n";
        cout<<"  1. Distance \n";
        cout<<"  2. Weight \n";
        cout<<"  3. Volume \n";
        cout<<"  4. Pressure \n";
        cout<<"  5. Temperature \n";
        cout<<"  6. Exit \n";
        cout<<"Choose the opteration you would like to complete: ";
        cin>>choice1; //First choice from userinput
        cout <<"--------------------------------------------------------\n"; 
        
        double num = 0;
        switch(choice1)
        {
            cout<<"\nSub menu: \n";
            //Distance
            case 1: cout<<"  1. Inch to centimeter |-1. for reverse \n";
                    cout<<"  2. Foot to meter |-2. for reverse \n";
                    cout<<"  3. Mile to kilometer |-3. for reverse \n";
                    cout<<"  4. Exit \n";
                    cout<<"Choose an operation: "; 
                    cin>>choice2; cout <<"--------------------------------------------------------\n";
                    
                    //User input for the conversion number
                    //Checks to make sure that it is a positive value
                    if(choice2 != 4)
                    {
                        cout<<"Enter the number to convert: ";
                        cin>>num;
                            while(num < 0)
                            {
                                cout<<"Enter the number to convert: ";
                                cin>>num; 
                            }
                    } 

                    //Performs conversions
                    switch(choice2)
                    {
                        case 1: cout<<"Inch to centimeter: "<<num*2.54; break;
                        case -1: cout<<"Centimeter to inch: "<<num/2.54; break;
                        case 2: cout<<"Foot to meter: "<<num*0.3048; break;
                        case -2: cout<<"Meter to foot: "<<num/0.3048; break;
                        case 3: cout<<"Mile to kilometer: "<<num*1.609; break;
                        case -3: cout<<"Kilometer to mile: "<<num/1,609; break;
                        case 4: break; 
                    } break;

            //Weight
            case 2: cout<<"  1. Ounce to gram |-1. for reverse \n";
                    cout<<"  2. Pound to kilogram |-2. for reverse \n"; 
                    cout<<"  3. Exit \n";
                    cout<<"Choose an operation: ";
                    cin>>choice2; cout <<"--------------------------------------------------------\n";

                    if(choice2 != 3)
                    {
                        cout<<"Enter the number to convert: "; //User input for the conversion number
                        cin>>num;
                            while(num < 0) //Checks to make sure that it is a positive value
                            {
                                cout<<"Enter the number to convert: ";
                                cin>>num; 
                            }
                    }

                    switch(choice2) //Performs conversions
                    {
                        case 1: cout<<"Ounce to gram: "<<num*28.349; break;
                        case -1: cout<<"Gram to Ounce: "<<num/28.349;; break;
                        case 2: cout<<"Pound to kilogram: "<<num*0.453; break;
                        case -2: cout<<"Kilogram to pound: "<<num/0.453; break;
                        case 3: break;
                    } break;

            //Volume
            case 3: cout<<"  1. Ounce to milliliter |-1. for reverse \n";
                    cout<<"  2. Gallon to liter |-2. for reverse \n";
                    cout<<"  3. Quarter to liter |-3. for reverse \n";
                    cout<<"  4. Exit \n";
                    cout<<"Choose an operation: ";
                    cin>>choice2; cout <<"--------------------------------------------------------\n";

                    if(choice2 != 4)
                    {
                        cout<<"Enter the number to convert: "; //User input for the conversion number
                        cin>>num;
                            while(num < 0) //Checks to make sure that it is a positive value
                            {
                                cout<<"Enter the number to convert: ";
                                cin>>num; 
                            }
                    }

                    switch(choice2) //Performs conversions
                    {
                        case 1: cout<<"Ounce to milliliter: "<<num*29.573; break;
                        case -1: cout<<"Milliliter to Ounce: "<<num/29.573; break;
                        case 2: cout<<"Gallon to liter: "<<num*3.785; break;
                        case -2: cout<<"Liter to Gallon: "<<num/3.785; break;
                        case 3: cout<<"Quarter to liter: "<<num*0.946; break;
                        case -3: cout<<"Liter to quarter: "<<num/0.946; break;  
                        case 4: break;            
                    } break;

            //Pressure
            case 4: cout<<"  1. PSI to kg/cm | -1. for reverse \n";
                    cout<<"  2. Exit \n";
                    cout<<"Choose an operation: ";
                    cin>>choice2; cout <<"--------------------------------------------------------\n";
                    
                    if(choice2 != 2)
                    {
                        cout<<"Enter the number to convert: "; //User input for the conversion number
                        cin>>num;
                            while(num < 0) //Checks to make sure that it is a positive value
                            {
                                cout<<"Enter the number to convert: ";
                                cin>>num; 
                            }
                    }

                    switch(choice2) //Performs conversions
                    {
                        case 1: cout<<"PSI to kg/cm: "<<num*0.07; break;
                        case -1: cout<<"Kg/cm to PSI: "<<num/0.07; break;
                        case 2: break; 
                    } break;

            //Temperature
            case 5: cout<<"Choose an operation: \n";
                    cout<<"  1. Fahrenheit to celsius |-1. for reverse \n";
                    cout<<"  2. Exit \n"; 
                    cin>>choice2; cout <<"--------------------------------------------------------\n";
                    
                    if(choice2 != 2)
                    {
                        cout<<"Enter the number to convert: "; //User input for the conversion number
                        cin>>num; //Can be a negative number
                    }

                    switch(choice2) //Performs conversions
                    {
                        case 1: cout<<"Fahrenheit to celsius: "<<(num-32)*5/9; break;
                        case -1: cout<<"Celsius to fahrenheit: "<<(num*9/5)+32; break; 
                        case 2: break; 
                    } break;
            }
    } 
    while(choice1 != 6);
    printf("\n\nProgrammer: Aditi Verma");
} 