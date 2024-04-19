/**
 * @name Aditi Verma
 *       ASSIGNMENT 3 - Chapter 13
 * @date 3/20/24
 */

#include <iostream>
#include <iomanip>
#include "DynamicStack.h"
using namespace std;

int main()
{
    //Create dynamic stack 
    DynamicStack stack;
    //Stores menu choice
    int input = 0;

    // Excecute menu until user exits
    do{
        // User input for menu
        cout<<"\n\n----------MENU----------";
        cout<<"\n1). Push";
        cout<<"\n2). Pop";
        cout<<"\n3). Capitalize";
        cout<<"\n4). Display Stack";
        cout<<"\n5). Make a Story";
        cout<<"\n6). Exit";
        cout<<"\n------------------------";
        cout<<"\nEnter menu choice: ";
        cin>>input;
        
        //Catch input error
        if (input < 1 || input > 6)
        {
            cout<<"\nWrong input, try again!";
        }
        
        // Switch statements for each menu selection
        string wordIn; //Stores word inputs
        switch(input)
        {
            case 1: //Push
                cout<<"\nEnter a word: ";
                cin>>wordIn;
                //Validate user input
                while(wordIn.length() > 10 || wordIn.length() < 1)
                {
                    cout<<"\nERROR: The word must be at least one character and no longer than 10 letters."<<endl;
                    cout<<"\nEnter a word: ";
                    cin>>wordIn;
                }
                stack.push(wordIn);
                break;
            case 2: //Pop
                stack.pop();
                break;
            case 3: //Capitalize
                stack.capitalize();
                break;
            case 4: //Display stack
                stack.displayStack();
                break;
            case 5: //Make a story
                stack.story();
                break;            
            case 6:
                cout<<"\nThank you!";
                break;
        }
    }
    while (input != 6); 
}