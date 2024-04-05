/**
 * @name Aditi Verma
 *       ASSIGNMENT 4 - Chapter 18
 * @date 4/4/24
 */

#include "BeadList.h"
#include <iostream>
using namespace std;

BeadList::~BeadList()
{
    ListNode *currentNode; //Move through list
    ListNode *nxt;
    currentNode = head;
    while(currentNode != nullptr)
    {
        nxt = currentNode->next;
        delete currentNode;
        currentNode = nxt;
    }
}

/** BeadList 
 * Adds new bead to the end of BeadList
 * @param  {string} bead : 
 */
void BeadList::appendNode(string bead)
{
    checkNode(bead); //Checks material validation
    ListNode *newNode; //Point to a new node
    ListNode *currentNode; //Move through list

    newNode = new ListNode;
    newNode->value = bead; //sets value of node to bead
    newNode->next = nullptr; //end of list is always a nullptr

    if(!head) //If no node in list 
    {
        head = newNode; //add newNode the first node
    }
    else //If list is not empty
    {
        currentNode = head; //node at head
        while(currentNode->next) //find last node in list
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode; //insert newNode at end
    }
}

/** BeadList 
 * Inserts bead at a specific position
 * Return 2 is position exists
 * Return -1 if position does not exist 
 * @param  {string} bead : 
 */
int BeadList::insertNode(string bead, int position)
{
    checkNode(bead);
    ListNode *newNode;
    ListNode *currentNode;
    ListNode *prev; //previous node

    newNode = new ListNode;
    newNode->value = bead;
    
    if(position == 0) //if insert first node
    {
        newNode->next = head;
        head = newNode;
        return 0;
    }
    
    if(!head) //If no node in list 
    {
        head = newNode; //add newNode the first node
        newNode->next = nullptr;
    }
    else //If list is not empty
    {
        currentNode = head; //node at head
        prev = nullptr; //initialize

        //skip all nodes that are before desired position
        while(currentNode != nullptr)
        {
            if(position == 0) //if currentNode position is at the desired position
            {
                prev->next = newNode; //node after prev is newNode
                newNode->next = currentNode; //node after newNode is currentNode
                return 0;
            }
            prev = currentNode;
            currentNode = currentNode->next;
            position--;
        }
    }
    return -1;
}

/** BeadList 
 * Deletes bead at a specific position 
 * Return 2 is position exists
 * Return -1 if position does not exist 
 * @param  {string} bead : 
 */
int BeadList::deleteNode(string bead, int position)
{
    checkNode(bead);
    ListNode *currentNode;
    ListNode *prev;
    
    if(!head) //If no node in list 
    {
        return 0;
    }
    if(position == 0) //if delete first node
    {
        head = head->next;
        return 0;
    }
    else
    {
        currentNode = head;
        //skip all node that does not equal to desired position
        while(currentNode != nullptr)
        {
            if(position == 0)
            {
                //link previous node to the node after currentNode
                prev->next = currentNode->next;
                delete currentNode; //delete currentNode
                return 0;
            }
            prev = currentNode;
            currentNode = currentNode->next;
            position--;
        }   
    }
    return -1;
}

/** BeadList 
 * Prints out the LinkedList
 */
void BeadList::displayList() const
{
    ListNode *currentNode; //Move through list
    currentNode = head;
    int i = 0; //position
    cout<<endl;
    while(currentNode) //while node exists
    {
        cout<<i<<". "<<currentNode->value<<endl; //print node value
        currentNode = currentNode->next;
        i++;
    }
}

int BeadList::searchNode(string bead)
{   
    ListNode *currentNode; //Move through list
    currentNode = head;
    int i = 0; //position
    while(currentNode) //while node exists
    {
        if(currentNode->value == bead)
        {
            return i;
        }
        currentNode = currentNode->next;
        i++;
    }
    return -1;
}

/** BeadList 
 * High level validation, checks material input
 * @param  {string} bead : 
 */
void BeadList::checkNode(string bead)
{
    if (!(bead == "turquoise" || bead == "coral" || bead == "gold" || bead == "copper"))
    {
        cout<<"\n"<<bead<<" is not a metal that we carry.";
        exit(EXIT_FAILURE);
    }
}