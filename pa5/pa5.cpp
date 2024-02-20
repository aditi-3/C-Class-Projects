#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string input = "";
    cout<<"\nEnter the filename for rainfall data (or -1 to quit): ";
    getline(cin >> ws, input);
    do
    {
        double rain[12];
        int i = 0;
        ifstream input_file(input);
        if(input_file.is_open()) //reads each line from the text file
        {
            string line;
            while(getline(input_file, line))
            {
                rain[i] = stod(line);
                i++;
            }  
            input_file.close();          
        }
        
        string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

        double sum = 0; // calculate the total rain fall
        for(int i = 0; i < 12; i++)
        {
            sum += rain[i];
        }
        cout<<"\nThe total: "<<sum<<" inches.";

        double average = sum/12; // average rain fall
        cout<<"\nThe average: "<<average<<" inches.";

        double min = rain[0]; // calculate minimum rain fall
        double max = rain[0]; // calculate maximum rain fall
        for(int i = 0; i < 12; i ++)
        {
            if(rain[i] < min)
            {
                min = rain[i];
            }
            if( rain[i] > max)
            {
                max = rain[i];
            }
        }
        
        string minMonths = "";
        string maxMonths = "";
        for(int i = 0; i < 12; i ++)
        {
            if(rain[i] == min)
            {
                minMonths = minMonths + months[i];
                minMonths += ", ";
            }
            if(rain[i] == max)
            {
                maxMonths = maxMonths + months[i];
                maxMonths += ", ";
            }
        }
        cout<<"\nThe largest: "<<max<<" inches in "<<maxMonths;
        cout<<"\nThe Smallest: "<<min<<" inches in "<<minMonths;

        cout<<"\n\nMonth"<<'\t'<<'\t'<<"Rainfall\n";
        for(int i = 0; i < 12; i++)
        {
            cout<<"\n"<<months[i]<<'\t'<<'\t'<<rain[i];
            if(rain[i] == min)
            {
                cout<<'\t'<<"(smallest)";
            }
            else if(rain[i] == max)
            {
                cout<<'\t'<<"(largest)";
            }
        }

        cout<< "\n\nEnter the filename for rainfall data (or -1 to quit): ";
        cin>>input;
    } 
    while(input != "-1");
}