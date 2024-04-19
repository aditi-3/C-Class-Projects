/**
 * @name Aditi Verma
 *       ASSIGNMENT 5 - Chapter 19
 * @date 4/18/24
 */

#include <iostream>
#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H
using namespace std;

class DynamicStack 
{
    private:
        //Structure for stack nodes
        struct StackNode
        {
            string value;
            struct StackNode *next;
        };

        StackNode *top; //Pointer to stack top

    public:
        //Constructor
        DynamicStack()
        {
            top = nullptr;
        }
        //Destructor
        ~DynamicStack();

        //linked list operations
        void push(string);
        void pop();
        void capitalize();
        void displayStack();
        void story();
        bool isEmpty();  
}; 
#endif