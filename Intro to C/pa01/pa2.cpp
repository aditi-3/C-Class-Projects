#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //User input for pool length, width, and depth (feet)
    double length;
    cout << "Enter pool length: ";
    cin >> length;

    double width;
    cout << "Enter pool width: ";
    cin >> width;

    double depth;
    cout << "Enter pool depth: ";
    cin >> depth;

    //Amount of water needed to fill the pool 3 inches below the top (feet^3)
    double waterVolume = length*width*(depth-0.25);

    //Cost of filling pool + one-time fee
    double cost = waterVolume*0.77 + 100;

    //Print all entered and calculated values
    printf("---------------------------------\n");
    printf("Pool length: %f\n", length);
    printf("Pool Width: %f\n", width);
    printf("Pool depth: %f\n", depth);
    printf("Water volume (3in from the top): %f\n", waterVolume); 
    printf("Cost: %f\n", cost);

    printf("Programmer: Aditi Verma");
}