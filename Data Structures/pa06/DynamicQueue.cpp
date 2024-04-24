/**
 * @name Aditi Verma
 *       ASSIGNMENT 5 - Chapter 19
 * @date 4/18/24
 */

#include "DynamicQueue.h"
#include <iostream>
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

void DynamicQueue::enqueue(string word)
{
    cout<<word<<" was added to the stack."<<endl;
}

void DynamicQueue::dequeue()
{

}

void DynamicQueue::display()
{

}

void DynamicQueue::clear()
{

}

bool DynamicQueue::isEmpty()
{
   
} 