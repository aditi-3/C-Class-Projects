/**
 * @name Aditi Verma
 *       ASSIGNMENT 5 - Chapter 19
 * @date 4/18/24
 */

#include "DynamicStack.h"
#include <iostream>
#include <vector>
using namespace std;

/** Destructor
 *  Deletes all node in list
 */
DynamicStack::~DynamicStack()
{
    StackNode *currentNode; //Move through list
    StackNode *nxt;
    currentNode = top;
    while(currentNode != nullptr)
    {
        nxt = currentNode->next;
        delete currentNode;
        currentNode = nxt;
    }
}

/** Push
 *  Adds new node to list at the top
 *  @param  {string} word : 
 */
void DynamicStack::push(string word)
{
    if(word.length() < 1 || word.length() > 10)
    {
        cout<<"The word must be at least one character and no longer than 10 letters."<<endl;
        exit(EXIT_FAILURE);
    }
    StackNode *newNode; //Point to a new node

    newNode = new StackNode;
    newNode->value = word; //sets value of node to word

    if(!isEmpty()) //If no node in list, add newNode the first node
    {
        top = newNode;
        newNode->next = nullptr;
    }
    else //If list is not empty, insert node before top
    {
        newNode->next = top;
        top = newNode;
    }
    cout<<word<<" was added to the stack."<<endl;
}

/** Pop
 *  Pops the value at the top of the stack
 *  @param  {string} word : 
 */
void DynamicStack::pop()
{
    StackNode *temp = nullptr; //Temporaty pointer
    string word;
    if(isEmpty()) //if list empty, nothing to pop
    {
        cout<<"The stack is empty."<<endl;
    }
    else //If list is not empty, pop value off top of stack
    {
        word = top->value; //Save top value
        temp = top->next; //Point node to next (2nd) value in list
        delete top;
        top = temp; //Sets 2nd node to 1st
    }
    cout<<word<< "was popped."<<endl;
}

/** Capitalize 
 *  Capitalizes all the words in the stack
 */
void DynamicStack::capitalize()
{
    StackNode *temp = top; //Temporaty pointer
    string tempWord = "";
    if(isEmpty()) //if list empty, nothing to pop
    {
        cout<<"The stack is empty."<<endl;
    }
    else
    {
        while(temp != nullptr)
        {
            for(char i: temp->value) //capitalize current word
            {
                tempWord += toupper(i);
            }
            temp->value = tempWord; //Set current word to caputalized version
            temp = temp->next;
        }
    }
    cout<<"The stack is capitalized."<<endl;
}

/** Display Stack 
 *  Prints out the Stack List
 */
void DynamicStack::displayStack()
{
    StackNode *currentNode; //Move through list
    currentNode = top;
    int i = 0; //position
    cout<<endl;
    while(currentNode) //while node exists
    {
        cout<<i<<". "<<currentNode->value<<endl; //print node value
        currentNode = currentNode->next;
        i++;
    }
}

/** Make a Story
 * Prints out a story using 5 words from the
 */
void DynamicStack::story()
{
    if(isEmpty()) //if list empty
    {
        cout<<"The stack is empty."<<endl;
    }
    else 
    {
        StackNode *currentNode; //Move through list
        currentNode = top;

        vector<string> words; 
        while(currentNode) //Store all stack values in a vector of strings
        {
            words.push_back(currentNode->value);
            currentNode = currentNode -> next;
        }

        if(words.size() > 5) //If there are enough words in stack
        {
            int i = 0;
            while(i < 5)
            {
                pop();
                i++;
            }
            //Print out story
            cout<<"I woke up from a "<< words[0] << " to face one of the most heebie-jeebie inducing " <<words[1] << " to man.";
            cout<<"Not only did it have a huge "<< words[2] << " on its forehead but it also smelled like"<< words[3] <<".";
            cout<<"Quite frankly, it reminded me of a " << words[4] <<".";
        }
        else
        {
            cout<<"Not enough words in stack."<<endl;
        }
    }
}

/** Is Empty 
 * Returns true if the stack is empty and false otherwise
 * @return {bool}  : 
 */
bool DynamicStack::isEmpty()
{
    bool empty;
    if(!top)
    {
        empty = true;
    }
    else
    {
        empty = false;
    }
    return empty;
} 