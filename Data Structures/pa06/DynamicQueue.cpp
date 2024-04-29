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
    numItems = 0;
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
    numItems++; //Update number of items
    cout<<n<<" was added to the queue."<<endl; //*************
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
        numItems--;
    }
}

/** NumCount
 * Returns the current number of items in the queue
 * @return {int}  : 
 */
int DynamicQueue::numCount()
{
    QueueNode* temp =  front;
    if(temp != nullptr)
    {
        temp = temp->next;
        return 1 + numCount();
    }
    else
    {
        return 0;
    }
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
    locate(temp->next, win);
}

/** Raffle
 * Picks a winner at random (1-500) and promts prize options if a winner exists
 */
void DynamicQueue::raffle()
{
   int num = rand() % 500 + 1;
   QueueNode* winner = locate(front, num);
   if(winner == nullptr)
   {
        cout<<"Winner not found."<<endl;
   }
   else
   {
        int input;
        cout<<"The winner is "<<winner->name<<"with raffle number "<<num<<"."<<endl;
        cout<<"Do you want:"<<endl;
        cout<<"1. A free t-shirt"<<endl;    
        cout<<"2. A free side dish"<<endl;   
        switch(input) 
        {
            case 1:
                cout<<"Enjoy your t-shirt!"<<endl;
            case 2:
                cout<<"Enjoy your side dish!"<<endl;    
            default:
                cout<<"Invalid option, sorry."<<endl;
        }
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
        cout<<"\n"<<"Name"<<"\t"<<"Ticket Number";
        while(temp != nullptr) //while node exists
        {
            cout<<"\n"<<setw(6)<<temp->name<<"\t"<<setw(10)<<temp->ticket;
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
   if(numItems > 0)
   {
    return false;
   }
   return true;
} 