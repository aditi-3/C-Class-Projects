#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool ascending(int h, int m) //function to check for ascending order
{
    int temp = h*100+m;
    string number = to_string(temp);
    string compare = number.substr(0,1); //holds the first int value
    
    while(number.size() > 1)
    {
        if(stoi(number.substr(1,1)) == (stoi(compare)+1))
        {         
            number = number.substr(1);
            compare = number.substr(0,1);
        }
        else{ return false; }
    }
}

bool descending(int h, int m) //function to check for descending order
{
    int temp = h*100+m;
    string number = to_string(temp);
    string compare = number.substr(0,1); //holds the first int value
    
    while(number.size() > 1)
    {
        if(stoi(number.substr(1,1)) == (stoi(compare)-1))
        {         
            number = number.substr(1);
            compare = number.substr(0,1);
        }
        else{ return false; }
    }
}

bool same_numbers(int h, int m) //function to check for same numbers
{
    int temp = h*100+m;
    string number = to_string(temp);
    string compare = number.substr(0,1); //holds the first int value
    
    while(number.size() > 1)
    {
        if(stoi(number.substr(1,1)) == (stoi(compare)))
        {         
            number = number.substr(1);
            compare = number.substr(0,1);
        }
        else{ return false; }
    }
}

bool lucky_times(string h, string m) //function to check for lucky times
{
    if((stoi(h.substr(0,1)) + stoi(h.substr(1,2))) == (stoi(m.substr(0,1))+stoi(m.substr(1,2))))
    {
        return true;
    }
    else
    { 
        return false; 
    }
}

bool is_time(string time) //makes sure time is in correct format HH:MM, not HHxMM for example
{
    if(time.find(":") != std::string::npos)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    string input = "";
    do
    {
        cout<<"\nEnter a time (HH:MM): ";
        cin>>input;
        string h = input.substr(0,input.find(':'));
        string m = input.substr(input.find(':')+1);
        int hour = stoi(input.substr(0,input.find(':')));
        int minute = stoi(input.substr(input.find(':')+1));

        while(hour < 1 || hour > 12) //Makes sure the hour is in between 1 and 12
        {
            cout<<"\nHour is not in between 1-12, please retry.";
            cout<<"\nEnter a time (HH:MM): ";
            cin>>input;
            hour = stoi(input.substr(0,input.find(':')));
            minute = stoi(input.substr(input.find(':')+1));
        }
        
        while(minute < 0 || minute > 59) //Makes sure the minute is in between 0 and 59
        {
            cout<<"\nMinute is not in between 0-59, please retry.";
            cout<<"\nEnter a time (HH:MM): ";
            cin>>input;
            hour = stoi(input.substr(0,input.find(':')));
            minute = stoi(input.substr(input.find(':')+1));
        }
        while(is_time(input)) //Makes sure the time is correctly formatted with ":"
        {
            cout<<"\nTime is not in the format HH:MM, please retry.";
            cout<<"\nEnter a time (HH:MM): ";
            cin>>input;
            hour = stoi(input.substr(0,input.find(':')));
            minute = stoi(input.substr(input.find(':')+1));
        }

        cout<<"\n"<<h<<":"<<m;
        if(lucky_times(h, m))
        {
            cout<<" is a lucky time";
        }
        else
        {
            cout<<" is a normal time";
        }
        if(ascending(hour, minute))
        {
            cout<<" -> UP! All dreams will come true.";
        }
        else if(descending(hour, minute))
        {
            cout<<" -> DOWN! The challenging road is ahead.";
        }
        else if(same_numbers(hour, minute))
        {
            cout<<" -> BINGO! Go to buy a lottery ticket.";
        }

        cout<<"\nRun again (y/n)? ";
        cin>>input;

    } while (input != "n");
    printf("\nProgrammer: Aditi Verma");
}

