/**
 * @name Aditi Verma
 *       ASSIGNMENT 5 - Chapter 19
 * @date 4/18/24
 */

#include "DynamicQueue.h"
#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h> //Random
using namespace std;

DynamicQueue::DynamicQueue()
{
    front = nullptr;
    rear = nullptr;
}

/** Destructor
 *  Deletes all node in list
 */
DynamicQueue::~DynamicQueue()
{
    clear();
}

/** Enqueue
 * Inserts name at the rear of the queue
 * @param  {string} name : 
 */
void DynamicQueue::enqueue(string n)
{
    if(n.length() < 1 || n.length() > 20)
    {
        cout<<"\nERROR: Name must be no longer than 20 letters."<<endl;
        exit(EXIT_FAILURE);
    }

    QueueNode *newNode = new QueueNode;
    newNode->name = n;
    ticketNum += 10;
    newNode->ticket = ticketNum;
    newNode->next = nullptr;

    if(isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    cout<<"Welcome "<<n<<"! Your raffle number is "<<ticketNum<<"."<<endl;
}

/** Dequeue
 * Removes values at the front of the queue
 */
void DynamicQueue::dequeue()
{
    QueueNode *temp = nullptr;
    if(isEmpty())
    {
        cout<<"\nThe queue is empty.";
    }
    else
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

/** countNodes [Private]
 * Calculates the current number of items in the queue
 * @return {int}  : 
 */
int DynamicQueue::countNodes(QueueNode* q)
{
    if(q != nullptr)
    {
        return 1 + countNodes(q->next);
    }
    else
    {
        return 0;
    }
}

/** numNodes 
 * Interface that calls countNodes() function
 * @return {int}  : 
 */
int DynamicQueue::numNodes()
{
    return countNodes(front);
}

/** Locate
 * Locates raffle winner, if not found, nullptr is returned
 * @param  {QueueNode*} temp, {int} win
 * @return {DynamicQueue::QueueNode*}  : 
 */
DynamicQueue::QueueNode* DynamicQueue::locate(QueueNode* temp, int win)
{
    if(temp->ticket == win)
    {
        return temp;
    }
    if(temp == nullptr)
    {
        return nullptr;
    }
    return locate(temp->next, win);
}

/** Raffle
 * Picks a winner at random (1-500) and promts prize options if a winner exists
 */
void DynamicQueue::raffle()
{
    srand(time(0));
    int num = (rand() % ticketNum/10) + 1;
    QueueNode* winner = locate(front, num*10);

    if(winner == nullptr)
    {
        cout<<"Winner not found."<<endl;
        return;
    }
    else
    {
        int in;
        cout<<"The winner is "<<winner->name<<" with raffle number "<<winner->ticket<<"."<<endl;
        cout<<"Do you want:"<<endl;
        cout<<"1. A free t-shirt"<<endl;    
        cout<<"2. A free side dish"<<endl;
        cout<<"Enter choice: ";
        cin>>in;
        switch(in) 
        {
            case 1:
                cout<<"\nEnjoy your t-shirt!";
                break;
            case 2:
                cout<<"\nEnjoy your side dish!";  
                break;
            default:
                cout<<"\nInvalid option, sorry.";
                break;
        }
        return;
    }
}

/** Display Queue
 * Prints out the name and ticket numbers of everyone in line
 */
void DynamicQueue::display()
{
    if(isEmpty())
    {
        cout<<"\nThe queue is empty.";
    }
    else
    {
        QueueNode *temp = front;
        cout<<"\n"<<"Name"<<"\t\t"<<"Ticket Number";
        while(temp != nullptr) //while node exists
        {
            cout<<"\n"<<temp->name<<"\t"<<setw(10)<<temp->ticket;
            temp = temp->next;
        } 
    }

}

/** Clear
 * dequeues all the elements in the queue
 */
void DynamicQueue::clear()
{
    while(!isEmpty())
    {
        dequeue();
    }
}

/** Is Empty
 * Checks if the queue is empty or not
 * @return {bool}  : 
 */
bool DynamicQueue::isEmpty()
{
    if(front)
    {
        return false;
    }
    return true;
} 