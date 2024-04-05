/**
 * @name Aditi Verma
 *       ASSIGNMENT 4 - Chapter 18
 * @date 4/4/24
 */

#include <iostream>
#include <iomanip>
#include "BeadList.h"
using namespace std;

int main()
{
    int input = 0; 
    BeadList list; //BeadList object
    // Excecute menu until user exits
    do{
        // User input for menu
        cout<<"\n\n----------MENU----------";
        cout<<"\n1). Append";
        cout<<"\n2). Insert";
        cout<<"\n3). Delete";
        cout<<"\n4). Print";
        cout<<"\n5). Search";
        cout<<"\n6). Exit";
        cout<<"\nEnter menu choice: ";
        cin>>input;
        
        //Catch input error
        if (input < 1 || input > 7)
        {
            cout<<"\nWrong input, try again!";
        }
        
        string material; //holds material input
        int pos; //holds position inputs
        
        switch(input) // Switch statements for each menu selection
        {
            case 1: //Append
                cout<<"\nEnter Bead Material: ";
                cin>>material;
                //Check input
                while(!(material == "turquoise" || material == "coral" || material == "gold" || material == "copper"))
                {
                    cout<<"\nError: "<<material<<" is not a metal that we carry.";
                    cout<<"\nEnter Bead Material: ";
                    cin>>material;
                }
                list.appendNode(material); //Call append function
                break;

            case 2: //Insert
                cout<<"\nEnter Bead Material: ";
                cin>>material;
                //Check input
                while(!(material == "turquoise" || material == "coral" || material == "gold" || material == "copper"))
                {
                    cout<<"\nError: "<<material<<" is not a metal that we carry.";
                    cout<<"\nEnter Bead Material: ";
                    cin>>material;
                }
                cout<<"\nEnter Position: ";
                cin>>pos;

                if(list.insertNode(material, pos) == -1) //If position exists
                {
                    cout<<"\nBead posistion "<<pos<<" does not exist."<<endl;
                }
                else
                {
                    cout<<"\n"<<material<<" has been inserted at position "<<pos<<"."<<endl;
                }
                break;

            case 3: //Delete
                cout<<"\nEnter Bead Material: ";
                cin>>material;
                while(!(material == "turquoise" || material == "coral" || material == "gold" || material == "copper"))
                {
                    cout<<"\nError: "<<material<<" is not a metal that we carry.";
                    cout<<"\nEnter Bead Material: ";
                    cin>>material;
                }
                cout<<"\nEnter Position: ";
                cin>>pos;

                if(list.deleteNode(material, pos) == -1 ) //If position exists
                {
                    cout<<"\nBead posistion "<<pos<<" does not exist."<<endl;
                }
                else
                {
                    cout<<"\n"<<material<<" has been deleted at position "<<pos<<"."<<endl;
                }
                break;

            case 4: //Print
                list.displayList();
                break;

            case 5: //Search
                cout<<"\nEnter Bead Material: ";
                cin>>material;
                while(!(material == "turquoise" || material == "coral" || material == "gold" || material == "copper"))
                {
                    cout<<"\nError: "<<material<<" is not a metal that we carry.";
                    cout<<"\nEnter Bead Material: ";
                    cin>>material;
                }
                
                if(list.searchNode(material) == -1) //If material does not exist
                {
                    cout<<"\n"<<material<<"bead does not exist."<<endl;
                }
                else
                {
                    cout<<"\nThere is a "<<material<<"bead at position "<<list.searchNode(material)<<"."<<endl;
                }
                break;

            case 6: //Exit
                cout<<"\nThank you!";
                break;
        }
    }
    while (input != 6); 
}