/**
 * @name Aditi Verma
 *       ASSIGNMENT 6 - Chapter 19
 * @date 4/24/24
 */

#include <iostream>
#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H
using namespace std;

class DynamicQueue
{
    private:
        //Structure for stack nodes
        struct QueueNode
        {
            string value;
            struct QueueNode *next;
        };

        QueueNode *front;
        QueueNode *rear;
        int numItems;

    public:
        //Constructor
        DynamicQueue();
        //Destructor
        ~DynamicQueue();

        //linked list operations
        void enqueue(string);
        void dequeue();
        bool isEmpty();  
        void numCount();
        void raffle();
        void display();
        void clear();
}; 
#endif