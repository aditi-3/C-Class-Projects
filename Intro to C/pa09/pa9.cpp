#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <cmath>
using namespace std;

class Date
{
    private:
        int month;
        int day;
        int year;    

    public:
        Date()
        {

        }

        Date(int m, int d, int y)
        {
            month = m;
            day = d;
            year = y;
        }

        Date(string temp)
        {
            
        }

        int getMonth()
        {
            return month;
        }
        int getDay()
        {
            return day;
        }
        int getYear()
        {
            return year;
        }

        string getMonthStr(int n)
        {
            array<string, 13> monthStr = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
            return monthStr[n];
        }

        bool isLeapYear(int y)
        {
            if(((y % 4 == 0)&&(y % 100 != 0)) || (y % 400 ==0))
            {
                cout<<y<<" -> Leap Year!";
                return true;
            }
            else
            { 
                cout<<y<<" -> NOT Leap Year!";
                return false; 
            }
        }

        bool check(string m, string d, string y)
        {
            bool output = true;
            int month = stoi(m);
            int day = stoi(d);
            int year = stoi(y);
            if(m.length() < 2 || m.length() > 2 || d.length() < 2 || d.length() > 2)
            {
                cout<<"\nInvalid date/wrong format: Use two digits for both month and day.";
                output = false;
            }
            else if ((month > 12 || month < 1) || (day > 31 || day < 1))
            {
                cout<<"\nInvalid date/wrong format: Incorrect month or day.";
                output = false;
            }
            else if (month == 2) //February
            {
                if(!isLeapYear(year) && day > 29)
                {
                    cout<<"\n"<<day<<" is not a valid day in "<< getMonthStr(month)<<".";
                    output = false;
                }
            }
            else if((month == 4 || month == 6 || month == 9 || month == 11)&&(day > 30)) //April, June, September, Novemper
            {
                cout<<"\n"<<day<<" is not a valid day in "<< getMonthStr(month)<<".";
                output = false;
            }
            return output;
        }
    int findD(string in)
    {
        int index = 0;
        for(int i = 0; i < in.size(); i++)
        {
            if(in[i] == '/')
            {
                index ++;
                break;
            }  
        }
        return index;
    }
};

int main()
{
    string input = " ";
    string m; 
    string d;
    string y; 
    cout<<"The program displays a valid date in three different formats. \nNote: All junk data will be rejected!";
    cout<<"\nEnter a date (mm/dd/yyyy) or -1 to end: ";
    cin>>input;   
    do
    {
        string temp = input;
        m = (temp.substr(0, temp.find("/")));
        temp = temp.substr(temp.find("/")+1);
        d = (temp.substr(0, temp.find("/")));
        temp = temp.substr(temp.find("/")+1);
        y = (temp.substr(0));
        Date date = Date();
        if(date.check(m, d, y) != false && date.findD(input) != 2)
        {
            date = Date(stoi(m), stoi(d), stoi(y));
            cout<<"\n\n"<<input<<" (US)";
            cout<<"\n"<<date.getMonthStr(date.getMonth())<<" "<<date.getDay()<<", "<<date.getYear()<<" (US expanded)";
            cout<<"\n"<<date.getDay()<<" "<<date.getMonthStr(date.getMonth())<<" "<<date.getYear()<<" (US military)";
            cout<<"\n"<<date.getYear()<<"-"<<date.getMonth()<<"-"<<date.getDay()<<" (International)"; 
               
            cout<<"\nRun again (y/n)? ";
            cin>>input; 
            if(input == "n")
            { break;}    
            cout<<"The program displays a valid date in three different formats. \nNote: All junk data will be rejected!";
            cout<<"\nEnter a date (mm/dd/yyyy) or -1 to end: ";
            cin>>input; 
            if(input == "-1")
            { break;}  
        }
        else
        {
            cout<<"\nRe-Enter a date (mm/dd/yyyy) or -1 to end: ";
            cin>>input;
            if(input == "-1")
            { break;} 
        }
    } while ((input != "-1") || (input != "n"));
    printf("\nProgrammer: Aditi Verma -- CISC 192 C++ programming");
}
