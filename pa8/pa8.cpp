#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <cmath>
using namespace std;

struct
{ 
    int numerator;
    int denominator;
} str;

void check(string in) //checks input and sets the numerator and denominator
{

    if (in.find('/') != -1)
    {
        str.numerator = stoi(in.substr(0,in.find('/')));
        str.denominator = stoi(in.substr(in.find('/')+1));
    }
    else
    {
        str.numerator = stoi(in);
        str.denominator = 1;
    }
}

void simplify() //simplifies fraction in array
{
    for(int x = (str.numerator * str.denominator); x > 1; x--)
    {
        if((str.numerator % x) == 0 && (str.denominator % x) == 0)
        {
            str.numerator = str.numerator / x;
            str.denominator = str.denominator / x;
        }
    }
}

int main()
{
    string input = "";
    array<int, 4> fractions;
    do 
    {
        // FIRST FRACTION
        cout << "\nEnter a rational number in the form q/p: ";
        cin>> input;

        check(input);
        simplify();
        cout<<"(Just checking, you entered: "<<str.numerator<<'/'<<str.denominator<<" -- reduced form)";
        fractions[0] = str.numerator;
        fractions[1] = str.denominator;

        // SECOND FRACTION
        cout << "\n\nEnter another rational number in the form q/p: ";
        cin>> input;

        check(input);     
        simplify();
        cout<<"(Just checking, you entered: "<<str.numerator<<'/'<<str.denominator<<" -- reduced form)";
        fractions[2] = str.numerator;
        fractions[3] = str.denominator;

        cout<<"\n\n\nResults of Arithmetic operations:";
        double decimal;
        
        //ADDITION
        str.numerator = fractions[0]*fractions[3]+fractions[1]*fractions[2];
        str.denominator = fractions[1]*fractions[3];
        simplify();
        decimal = str.numerator/(double)str.denominator;
        cout<<"\n"<<fractions[0]<<"/"<<fractions[1]<<" + "<<fractions[2]<<"/"<<fractions[3]<<" = "<<str.numerator<<"/"<<str.denominator<<" = "<<round(decimal*100)/100;
        
        //SUBTRACTION
        str.numerator = fractions[0]*fractions[3]-fractions[1]*fractions[2];
        str.denominator = fractions[1]*fractions[3];
        simplify();
        decimal = str.numerator/(double)str.denominator;
        cout<<"\n"<<fractions[0]<<"/"<<fractions[1]<<" - "<<fractions[2]<<"/"<<fractions[3]<<" = "<<str.numerator<<"/"<<str.denominator<<" = "<<round(decimal*100)/100 ;        

        //MULTIPLICATION
        str.numerator = fractions[0]*fractions[2];
        str.denominator = fractions[1]*fractions[3];
        simplify();
        decimal = str.numerator/(double)str.denominator;
        cout<<"\n"<<fractions[0]<<"/"<<fractions[1]<<" * "<<fractions[2]<<"/"<<fractions[3]<<" = "<<str.numerator<<"/"<<str.denominator<<" = "<<round(decimal*100)/100;
        
        //DIVISION
        str.numerator = fractions[0]*fractions[3];
        str.denominator = fractions[1]*fractions[2];
        simplify();
        decimal = str.numerator/(double)str.denominator;
        cout<<"\n"<<fractions[0]<<"/"<<fractions[1]<<" / "<<fractions[2]<<"/"<<fractions[3]<<" = "<<str.numerator<<"/"<<str.denominator<<" = "<<round(decimal*100)/100;

        //EXIT
        cout<<"\nRun again (y/n)? ";
        cin>>input;
    } while (input != "n");
    printf("\nProgrammer: Aditi Verma -- CISC 192 C++ programming");
}
