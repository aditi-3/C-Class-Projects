#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double calculateCutSize(double len, double wid)
{
    int a = 12;
    int b = (-4)*(len+wid);
    int c = wid*len;
    double x1 = (-b + sqrt(pow(b,2)-(4*a*c)))/(2*a);
    double x2 = (-b - sqrt(pow(b,2)-(4*a*c)))/(2*a);
    if(x1 > 0 && x1 < x2)
    {
        return x1;
    } 
    else
    {
        return x2;
    }
}

double calculateVolume(double cut, double len, double wid)
{
    return (cut)*(len-(2*cut))*(wid-(2*cut)); 
}

void run()
{
    double length, width, cutSize, volume;
    string input = "";
    do
    {
        cout<<"\nThe given length of the cardboard: ";
        cin>>length;
        cout<<"\nThe given width of the cardboard: ";
        cin>>width;
        cutSize = calculateCutSize(length, width);
        cout<<"\nThe size of the cut: "<<cutSize;
        volume = calculateVolume(cutSize, length, width);
        cout<<"\nThe maximum volume of the opened box: "<<volume;
        cout<<"\nRun the program again? (y/n)";
        cin>>input;
        if (input == "n")
        {
            break;
        }
    } while(input != "n");
    cout<<"\nProgrammer: Aditi Verma";
}

int main()
{
    run();
}