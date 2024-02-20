#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>       

using namespace std;



void print()
{
    string yn;
    double length;
    double width;
    double a,b,c;
    double x1, x2;
    double volume;
    double sizeCut;

    do{
        cout << "Enter Length: ";
    cin >> length;
    cout << "Enter Width: ";
    cin >> width;

    a = 12;
    b = (-4) *(length + width);
    c = length * width;

    x1 = (-b + sqrt(pow(b,2) - (4 * a * c))) / (2 * a);
    x2 = (-b - sqrt(pow(b,2) - (4 * a * c))) / (2 * a);


    if(x1 * 24 - (4 * (length + width)) < 0)
    {
        volume = ((length - (2 * x1)) *(width - (2 * x1)) * x1);
        sizeCut = x1;
        
        
    }
    else if(x2 * 24 - 4 * (length + width) < 0)
    {
        volume = ((length - (2 * x2)) *(width - (2 * x2)) * x2);
        sizeCut = x2;

        
    }
    
    

    cout<< "The given length of the cardboard: " << length << "\n";
    cout << "The given width of the cardboard: " << width << "\n";
    cout << "the maximum volume of the opened box: " << volume<< "\n";
    cout << "The size of the cut: " << sizeCut<< "\n";
    cout << "Run the program again (y/n)?"<< "\n";
    cin >> yn;

    }while(yn.compare("n"));

    cout << "wrote by seojin Park";




}

int main(){
    print();

}