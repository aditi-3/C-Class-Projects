#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <cmath>
#include <iomanip>
using namespace std;

class NumberPattern
{
    private:
        array<string, 20> order;
        array<long long, 20> number;

    public:
        NumberPattern()
        {
            order = {"1st", "2nd", "3rd", "4th", "5th","6th","7th","8th","9th","10th","11th","12th","13th","14th","15th","16th","17th","18th","19th","20th"};
            for(int i = 1; i <= number.size(); i++)
            {
                number[i-1] = getNumber(i);
            }
        }

        void printArray()
        {
            cout<<"\nThe first twenty numbres in the pattern: ";
            cout<<"Order"<<'\t'<<"Number";
            for(int i = 0; i < order.size(); i++)
            {
                cout<<"\n"<<order[i]<<'\t'<<number[i];
            }
        }

        long long getNumber(int o)
        {
            long long number = 0;
            for(int i = 1; i <= o; i ++)
            {
                number = number + pow(i, 2);
            }
            return number;
        }
};

int main()
{
    string input = "";
    NumberPattern object = NumberPattern();
    object.printArray();
    do
    {
        cout<<"\nWhat's the ordered element in the pattern that you wanted to find?\n(Or enter 0 to end): ";
        cin>>input;
        if(input == "0")
        {
            break;
        }
        long long number = object.getNumber(stoi(input));
        cout<<"\nThe "<<input<<"th element is: "<<number;
    } while (input != "0");
    cout<<"\nGOOD BYE!";
    cout<<"\nProgrammer: Aditi Verma -- CISC 192 C++ programming";
}