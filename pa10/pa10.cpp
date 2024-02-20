#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    string input ="";
    
    string vowels = "AEIOUaeiou";
    string consonants = "BCDFGHJKLMNPQRSTVXYZbcdfghjklmnpqrstvxyz";
    string digits = "0123456789";

    int dNum = 0;
    int vNum = 0;
    int cNum = 0;

    string d = "";
    string v = "";
    string c = "";

    do
    {
        cout<<"\nFrom a string entered at the keyboard, the program\ncounts and lists the number of digits, vowels, and consonants.";
        cout<<"\nEnter a string: ";
        getline(cin, input);
        for(int i = 0; i < input.size();i ++)
        {
            for(int x = 0; x < consonants.size(); x ++)
            {
                if (input[i] == consonants[x])
                {
                    c += input[i];
                    c +=  ", ";
                    cNum++;
                }
            }   
            for(int x = 0; x < vowels.size(); x++)
            {
                if(input[i] == vowels[x])
                {
                    v += input[i];
                    v +=  ", ";
                    vNum++;
                }
            }
            for (int x = 0; x < digits.size(); x++)
            {
                if(input[i] == digits[x])
                {
                    d += input[i];
                    d +=  ", ";
                    dNum++;
                }
            }
        }

        cout<<"\nDigits: "<<dNum<<" --> "<<d;
        cout<<"\nVowels: "<<vNum<<" --> "<<v;
        cout<<"\nConsonants: "<<cNum<<" --> "<<c;
        
        c = "";
        v = "";
        d = "";
        cout<<"\nRun again (y/n): ";
        cin>>input;
    } while (input != "n");
    cout<<"Programmer: Aditi Verma -- Intro to Programming C++";
} 