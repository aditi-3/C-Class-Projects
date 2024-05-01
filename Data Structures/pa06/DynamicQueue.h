/**
 * @name Aditi Verma
 *       ASSIGNMENT 6 - Chapter 19
 * @date 4/24/24
 */

#include <iostream>
#include <vector>
#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H
using namespace std;

class DynamicQueue
{
    private:
        //Structure for stack nodes
        struct QueueNode
        {
            string name;
            int ticket;
            struct QueueNode *next;
        };

        QueueNode *front;
        QueueNode *rear;
        int ticketNum;
        int countNodes(QueueNode*);

    public:
        //Constructor
        DynamicQueue();
        //Destructor
        ~DynamicQueue();

        //linked list operations
        void enqueue(string);
        void dequeue();
        int numNodes();
        QueueNode* locate(QueueNode*, int);
        void raffle();
        void display();
        void clear();
        bool isEmpty();  
}; 
#endif