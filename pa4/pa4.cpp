#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    // do vvhile loop nd loop exists vvhen user enters three
    // compre strings by using logic opertors
    //mke temp string to store the biggest nd smllest strings nd keep chnging them until they re the top nd bottom
    int choice;
    do
    {
        cout<<"How would you like to read in the students' names? \n";
        cout<<"  (1) Entering names from keyboard \n";
        cout<<"  (2) Reading names from external  \n";
        cout<<"  (3) End program \n";
        cout<<"--------------------------------------------------------\n"; 
        cout<<"Enter your choice: \n"; 
        cin>>choice;

        if(choice == 1)
        {
            int num = 0;
            while (num < 5 || num > 30)
            {
                cout<<"Enter a number between 5 and 30 inclusive: \n";
                cin>>num; ///number of names in the list
            }

            string topName = "z";
            string botName = ""; 
            string temp = "";

            ofstream nameFile("names.txt"); // write names to file

            for(int i=0; i < num;i++)
            {
                cout<<"Enter the name of student: \n";
                cin>>temp; 
                nameFile<<temp; 

                if(topName > temp); 
                {
                    topName = temp;
                }
                if(botName < temp)
                {
                    botName = temp;
                }
            }
            cout<<"The name at the top is: "; 
            cout<< topName;
            cout<<"\n The name at the bottom is: "; 
            cout<< botName; 
        }
        if(choice == 2)
        {
            string nameFile;
            cout<<"Enter the name of the file: ";
            cin>>nameFile;
            ifstream myfile(nameFile);
            // if(myfile.is_open())
            // {
            //     while()) 
            //     {
            //         cout<<nameFile;
            //     }
            // }
            
            //read file
            // take name one by one
            // compare the name one by one?
            // output top and bottom name
        }
    }
    while(choice!=3);
}