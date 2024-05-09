/**
 * @name Aditi Verma
 *       ASSIGNMENT 7 - Chapter 21
 * @date 5/8/24
 */

#include <iostream>
#include <iomanip>
#include "BinaryTree.h"
using namespace std;

int main()
{
    //Create dynamic queue 
    BinaryTree tree;
    //Stores menu choice
    int input = 0;

    // Excecute menu until user exits
    do {
        // User input for menu
        cout<<"\n\n----------MENU----------";
        cout<<"\n1). Insert";
        cout<<"\n2). Display in order";
        cout<<"\n3). Leaf count";
        cout<<"\n4). Tree height";
        cout<<"\n5). Tree width";
        cout<<"\n6). Exit";
        cout<<"\n------------------------";
        cout<<"\nEnter menu choice: ";
        cin>>input;
        
        // Switch statements for each menu selection
        int numIn; //Stores string inputs
        switch(input)
        {
            case 1: //Insert
                cout<<"\nEnter a number: ";
                cin>>numIn;          
                tree.insertNode(numIn);
                break;
            case 2: //Display in order
                tree.displayInOrder();
                break;
            case 3: //Leaf Count
                cout<<"There are "<<tree.leafCount()<<" leaves in the tree."<<endl;
                break;
            case 4: //Tree height
                tree.treeHeight();
                break;
            case 5: //Tree width
                tree.treeWidth();
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