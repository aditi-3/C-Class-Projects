#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <cmath>
#include <iomanip>
using namespace std;

class NumDays
{
    private:
        int hours;
        int days;

    public:
        NumDays()
        {

        }
        NumDays(int h)
        {
            hours = h;
        }

        int getHours()
        {
            return hours;
        }
        float getDays()
        {
            float days = hours/8.0;
            return round(days*100)/100;
        }
        void setHours(int h)
        {
            hours = h;
        }
        void setDays(int d)
        {
            days = d;    
        }

        NumDays operator+(NumDays const& obj)
        {
            NumDays x;
            x.hours = hours + obj.hours;
            return x;
        }

        NumDays operator-(NumDays const& obj)
        {
            NumDays x;
            x.hours = hours - obj.hours;
            return x;
        }

        NumDays& operator++()
        {
            hours += 2;
            return *this;
        }

        NumDays& operator--()
        {
            hours -= 2;
            return *this;
        }
};

int main()
{
    string input = "";   
    do
    {
        cout<<"\nEnter the number of work hours: ";
        cin>>input;

        int hours1 = stoi(input);
        NumDays numDays1 = NumDays(hours1);
        cout<<"One: "<<setprecision(3)<<numDays1.getDays()<<" days.";
        
        cout<<"\n\nEnter another number of work hours: ";
        cin>>input;
        
        int hours2 = stoi(input);
        NumDays numDays2 = NumDays(hours2);
        cout<<"Two: "<<setprecision(3)<<numDays2.getDays()<<" days.";

        NumDays add = numDays1+numDays2;
        NumDays sub = numDays1-numDays2;
        cout<<"\n\nAddition: One + Two: "<<setprecision(3)<<add.getDays()<<" days.";
        cout<<"\nSubtraction: One - Two: "<<setprecision(3)<<sub.getDays()<<" days.";
        
        cout<<"\n\nOne++: "<<setprecision(3)<<numDays1.getDays();
        ++numDays1;
        cout<<"\n++One: "<<setprecision(3)<<numDays1.getDays();

        cout<<"\n\nTwo--: "<<setprecision(3)<<numDays2.getDays();
        --numDays2;
        cout<<"\n--Two: "<<setprecision(3)<<numDays2.getDays();

        cout<<"\nTest the program again (y/n)? ";
        cin>>input;   
        if(input == "n")
        {
            break;
        }
        cout<<"\n-------------------------------------------------------";

    } while ((input != "-1") || (input != "n"));
    printf("\nProgrammer: Aditi Verma -- CISC 192 C++ programming");
}
