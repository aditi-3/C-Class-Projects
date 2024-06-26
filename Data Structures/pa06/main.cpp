/**
 * @name Aditi Verma
 *       ASSIGNMENT 3 - Chapter 13
 * @date 3/20/24
 */

#include <iostream>
#include <iomanip>
#include "DynamicQueue.h"
using namespace std;

int main()
{
    //Create dynamic queue 
    DynamicQueue queue;
    //Stores menu choice
    int input = 0;

    // Excecute menu until user exits
    do {
        // User input for menu
        cout<<"\n\n----------MENU----------";
        cout<<"\n1). Add name";
        cout<<"\n2). Make an Order";
        cout<<"\n3). Count Names";
        cout<<"\n4). Draw Raffle Winner";
        cout<<"\n5). Display Line";
        cout<<"\n6). Exit";
        cout<<"\n------------------------";
        cout<<"\nEnter menu choice: ";
        cin>>input;
        
        // Switch statements for each menu selection
        string wordIn; //Stores string inputs
        switch(input)
        {
            case 1: //Add name
                cout<<"\nEnter your name: ";
                cin>>wordIn;          
                while(wordIn.length() > 20 || wordIn.length() < 1)
                {
                    cout<<"\nERROR: Name must be no longer than 20 letters."<<endl;
                    cout<<"\nEnter your name: ";
                    cin>>wordIn;
                }
                queue.enqueue(wordIn);
                break;
            case 2: //Make an Order
                queue.dequeue();
                break;
            case 3: //Count Names
                cout<<"There are "<<queue.numNodes()<<" people in line."<<endl;
                break;
            case 4: //Draw raffle winner
                queue.raffle();
                break;
            case 5: //Display queue
                queue.display();
                break;            
            case 6:
                cout<<"\nThank you!";
                break;
            default: 
                cout<<"\nWrong input, try again!";
                break;
        }
    }
    while (input != 6); 
}