#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //User input for pool length, width, and depth (feet)
    double length;
    cout << "Enter pool length: ";
    cin >> length;
    while (length < 0) //Variable has to be a positive real number
    {
        cout << "Enter pool length: ";
        cin >> length;
    }

    double width;
    cout << "Enter pool width: ";
    cin >> width;
    while (width < 0) //Variable has to be a positive real number
    {
        cout << "Enter pool width: ";
        cin >> width;
    }

    double depth;
    cout << "Enter pool depth: ";
    cin >> depth;
    while (depth < 0) //Variable has to be a positive number
    {
        cout << "Enter pool depth: ";
        cin >> depth;
    }

    //Amount of water needed to fill the pool 3 inches below the top (feet^3)
    double waterVolume;
    if (depth <= 0.25) // checks depth to see if it is over 3 inches from the top
    {
        waterVolume = 0;
    }
    else
    {
        waterVolume = length*width*(depth-0.25);
    }

    //Cost of filling pool + one-time fee
    double cost;
    if(waterVolume > 0) // makes sure water volume is greater than zero for the one-time fee to apply
    {
        cost = waterVolume*0.77 + 100;
    }
    else
    {
        cost = 0;
    }
     
    //Print all entered and calculated values
    printf("---------------------------------\n");
    printf("Pool length (ft): %f\n", length);
    printf("Pool Width (ft): %f\n", width);
    printf("Pool depth (ft): %f\n", depth);
    printf("Pool Volume (ft^3):  %f\n", length*width*depth);
    printf("Water volume (3in from the top, ft^3): %f\n", waterVolume); 
    printf("Cost: $%f\n", cost);

    printf("\nProgrammer: Aditi Verma");
}