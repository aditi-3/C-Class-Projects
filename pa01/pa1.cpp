/*
Write a C++ program that can calculate and display the area and perimeter of any rectangle 
whose size was entered at the run time of the program (all positive real numbers 
should be accepted - 2 points for this requirement).
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double a; //Side length 1
    cout << "Enter one side length of the rectangle: ";
    cin >> a;
    while (a <= 0) //Variable has to be a positive real number
    {
        cout << "Enter one side length of the rectangle: ";
        cin >> a;
    }

    double b; //Side length 2
    cout << "Enter another side length of the rectangle: ";
    cin >> b; 

    while (b <= 0) //Variable b has to be a positive real number
    {
        cout << "Enter another side length of the rectangle: ";
        cin >> b;
    }

    //Calculate area and perimeter
    double perimeter = 2*a+2*b;
    double area = a*b;
    //Print area and perimeter
    printf("Perimeter: %f\n", perimeter);
    printf("Area: %f\n", area);
    printf("Programmer: Aditi Verma");
}


